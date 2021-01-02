module SymbolicDifferentiationOfPrefixExpressions (diff) where

import Control.Monad
import Data.Char
import Text.Parsec
import Text.Parsec.String
import Text.Printf

data AST
  = Add [AST]
  | Sub [AST]
  | Mul [AST]
  | Div [AST]
  | Pow AST Integer
  | Fn String [AST]
  | I Float
  | N String
  deriving (Show, Eq)

type Operator = [AST] -> AST

op :: Char -> Operator
op x =
  case x of
    '+' -> Add
    '-' -> Sub
    '*' -> Mul
    '/' -> Div
    _ -> error "impossible"

ast :: Parser AST
ast =
  ( between
      (char '(' <* spaces)
      (char ')' <* spaces)
      ( choice
          [ operator,
            pow,
            function
          ]
      )
      <|> number
      <|> var
  )
    <* spaces
  where
    operator = do
      oper <- satisfy (`elem` "+-*/")
      spaces
      op oper <$> many1 ast
    pow = do
      char '^'
      spaces
      Pow <$> ast <*> (read <$> many1 digit)
    function = do
      name <- many1 letter
      guard $ name `elem` ["sin", "cos", "tan", "exp", "ln"]
      spaces
      Fn name <$> many ast
    number = I . read <$> many1 digit
    var = N <$> many1 letter

parse' :: String -> AST
parse' s =
  case parse ast "" s of
    Right ast -> ast
    _ -> error "parse failed"

unparse :: AST -> String
unparse ast =
  case ast of
    Add xs -> printf "(+ %s)" (f xs)
    Sub xs -> printf "(- %s)" (f xs)
    Mul xs -> printf "(* %s)" (f xs)
    Div xs -> printf "(/ %s)" (f xs)
    Pow a n -> printf "(^ %s %d)" (unparse a) n
    Fn name xs -> printf "(%s %s)" name (f xs)
    I i
      | isInt i -> show $ round i
      | otherwise -> show i
    N n -> n
  where
    f = unwords . map unparse
    isInt x = x == fromInteger (round x)

simp :: AST -> AST
simp ast =
  case ast of
    Add xs ->
      case filter (/= I 0) $ map simp xs of
        [] -> I 0
        [x] -> x
        xs'
          | all isI xs' -> I $ sumI xs'
          | otherwise -> Add xs'
    Sub xs ->
      case map simp xs of
        [] -> I 0
        [x] -> x
        I b : xs'
          | all isI xs' -> I (b - sumI xs')
        xs' -> Sub xs'
    Mul xs ->
      case filter (/= I 1) $ map simp xs of
        [] -> I 1
        [x] -> x
        xs'
          | I 0 `elem` xs' -> I 0
          | all isI xs' -> I $ product $ map getI xs'
          | all (\x -> isI x || isMul x) xs' ->
            let b = simp $ Mul $ filter isI xs'
                xs'' = map (\(Mul m) -> simp $ Mul (b : m)) $ filter isMul xs'
             in simp $ Mul xs''
          | otherwise ->
            let is = filter isI xs'
                xs'' = filter (not . isI) xs'
             in case is of
                  [] -> Mul xs'
                  [x] -> Mul (x : xs'')
                  _ -> Mul (simp (Mul is) : xs'')
    Div xs ->
      case map simp xs of
        [x] -> x
        xs'
          | all isI xs' ->
            case xs' of
              I b : xs'' -> I (b / sumI xs'')
              _ -> error ""
          | otherwise -> Div xs'
    Pow x e
      | e == 0 -> I 1
      | e == 1 -> x
      | otherwise ->
        case simp x of
          I i -> I $ i ^ e
          x' -> Pow x' e
    Fn n xs -> Fn n (map simp xs)
    _ -> ast
  where
    isI (I _) = True
    isI _ = False
    getI (I x) = x
    sumI = sum . map getI
    isMul (Mul _) = True
    isMul _ = False
    getMul (Mul x) = x
    isIMul x = isI x || isMul x

diff' :: AST -> AST
diff' ast =
  simp $ case ast of
    I _ -> I 0
    N _ -> I 1
    Add xs -> Add $ map diff' xs
    Sub xs -> Sub $ map diff' xs
    Pow x a -> Mul [I $ fromIntegral a, Pow x (a -1)]
    Mul [x] -> diff' $ Mul [x, I 1]
    Mul [x, y] -> Add [Mul [diff' x, y], Mul [x, diff' y]]
    Mul (x : xs) -> Add [Mul [diff' x, Mul xs], Mul [x, diff' (Mul xs)]]
    Div (x : xs) -> Div [Sub [Mul [diff' x, Mul xs], Mul [x, diff' (Mul xs)]], Pow (Mul xs) 2]
    Fn n [x]
      | n == "sin" -> chain (Fn "cos" [x]) x
      | n == "cos" -> chain (Mul [I (-1), Fn "sin" [x]]) x
      | n == "tan" -> chain (Add [I 1, Pow (Fn "tan" [x]) 2]) x
      | n == "ln" -> chain (Div $ I 1 : [x]) x
      | n == "exp" -> chain ast x
      | otherwise -> chain ast x
    _ -> ast
  where
    chain f' g = Mul [f', diff' g]

diff :: String -> String
diff = unparse . diff' . parse'
