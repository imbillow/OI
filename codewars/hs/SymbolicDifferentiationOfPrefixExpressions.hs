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
  | I Integer
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
      guard $ name `elem` ["sin", "cos"]
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
    I i -> show i
    N n -> n
  where
    f = unwords . map unparse

diff :: String -> String
diff = undefined
