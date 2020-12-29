module SymbolicDifferentiationOfPrefixExpressions (diff) where

import Control.Monad
import Data.Char
import Text.Parsec
import Text.Parsec.String

data AST
  = Add AST AST
  | Sub AST AST
  | Mul AST AST
  | Div AST AST
  | Pow AST Integer
  | Fn String AST
  | I Integer
  | N String
  deriving (Show, Eq)

type Operator = AST -> AST -> AST

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
            function,
            number,
            var
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
      op oper <$> ast <*> ast
    pow = do
      char '^'
      spaces
      Pow <$> ast <*> (read <$> many1 digit)
    function = do
      name <- many1 letter
      guard $ name `elem` ["sin", "cos"]
      spaces
      Fn name <$> ast
    number = I . read <$> many1 digit
    var = N <$> many1 letter

diff :: String -> String
diff = undefined
