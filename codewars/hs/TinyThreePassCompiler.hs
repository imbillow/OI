module TinyThreePassCompiler where

import Data.Either
import Data.Functor
import Data.List
import Data.Maybe
import Text.Parsec

data AST
  = Imm Int
  | Arg Int
  | Add AST AST
  | Sub AST AST
  | Mul AST AST
  | Div AST AST
  | Name String
  deriving (Eq, Show)

compile :: String -> [String]
compile = pass3 . pass2 . pass1

type Operator = AST -> AST -> AST

op :: Char -> Operator
op x =
  case x of
    '+' -> Add
    '-' -> Sub
    '*' -> Mul
    '/' -> Div
    _ -> error "impossible"

opOf :: [Char] -> Parsec String st Operator
opOf xs =
  op <$> oneOf xs <* spaces

immP, argP, exprP, termP, factorP :: Parsec String st AST
immP = Imm . read <$> many1 digit <* spaces
argP = Name <$> many1 letter <* spaces
exprP = spaces *> (chainl1 termP (opOf "+-") <* spaces)
termP = chainl1 factorP (opOf "*/") <* spaces
factorP = choice [immP, argP, pareP] <* spaces
  where
    pareP = between (char '(') (char ')') exprP

argsP :: Parsec String st [String]
argsP =
  spaces
    *> between
      (char '[' <* spaces)
      (char ']')
      (many $ many1 letter <* spaces)

pass1 :: String -> AST
pass1 inp =
  let (l, _ : r) = break (`elem` "[]") $ tail inp
      ast =
        do
          args <- parse argsP "" $ '[' : l ++ "]"
          ast' <- parse exprP "" r
          return $ rewrite ast' args
   in case ast of
        Right ast' -> ast'
        Left e -> error $ show e
  where
    rewrite ast args =
      case ast of
        Name n -> Arg $ fromJust $ elemIndex n args
        Mul a b -> f Mul a b
        Div a b -> f Div a b
        Add a b -> f Add a b
        Sub a b -> f Sub a b
        _ -> ast
      where
        f o a b = o (rewrite a args) $ rewrite b args

pass2 :: AST -> AST
pass2 ast =
  case ast of
    Add a b -> fn (+) Add a b
    Sub a b -> fn (-) Sub a b
    Mul a b -> fn (*) Mul a b
    Div a b -> fn div Div a b
    _ -> ast
  where
    fn f1 f2 a b =
      case (pass2 a, pass2 b) of
        (Imm a', Imm b') -> Imm $ f1 a' b'
        (a', b') -> f2 a' b'

pass3 :: AST -> [String]
pass3 ast =
  case ast of
    Add a b -> op2 "AD" a b
    Sub a b -> op2 "SU" a b
    Mul a b -> op2 "MU" a b
    Div a b -> op2 "DI" a b
    Imm i -> ["IM " ++ show i]
    Arg i -> ["AR " ++ show i]
  where
    op2 i a b = pass3 a ++ ["PU"] ++ pass3 b ++ ["SW", "PO", i]
