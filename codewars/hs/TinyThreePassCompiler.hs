{-# LANGUAGE TupleSections #-}

module TinyThreePassCompiler where

import Data.Functor
import Data.List
import Data.Maybe

data AST
  = Imm Int
  | Arg Int
  | Add AST AST
  | Sub AST AST
  | Mul AST AST
  | Div AST AST
  deriving (Eq, Show)

data Token
  = TChar Char
  | TInt Int
  | TStr String
  | TokEnd
  deriving (Eq, Show)

alpha, digit :: String
alpha = ['a' .. 'z'] ++ ['A' .. 'Z']
digit = ['0' .. '9']

tokenize :: String -> [Token]
tokenize [] = []
tokenize xxs@(c : cs)
  | c `elem` "-+*/()[]" = TChar c : tokenize cs
  | not (null i) = TInt (read i) : tokenize is
  | not (null s) = TStr s : tokenize ss
  | otherwise = tokenize cs
  where
    (i, is) = span (`elem` digit) xxs
    (s, ss) = span (`elem` alpha) xxs

compile :: String -> [String]
compile = pass3 . pass2 . pass1

argumemts :: [Token] -> ([String], [Token])
argumemts ts = arg ts []
  where
    arg ts =
      case lookAhead ts of
        TChar c
          | c == '[' -> arg $ accept ts
          | c == ']' -> (,accept ts)
        TStr s -> arg (accept ts) . (++ [s])
        _ -> error ""

op :: Char -> AST -> AST -> AST
op x =
  case x of
    '+' -> Add
    '-' -> Sub
    '*' -> Mul
    '/' -> Div
    _ -> error "impossible"

lookAhead :: [Token] -> Token
lookAhead [] = TokEnd
lookAhead ts = head ts

accept :: [Token] -> [Token]
accept [] = error "Nothing to accept"
accept ts = tail ts

expression, term, factor :: [String] -> [Token] -> (AST, [Token])
expression args toks =
  let (t, toks') = term args toks
   in case lookAhead toks' of
        (TChar c)
          | c `elem` "+-" ->
            let (e, toks'') = expression args $ accept toks'
             in (op c t e, toks'')
        _ -> (t, toks')
term args toks =
  let (f, toks') = factor args toks
   in case lookAhead toks' of
        (TChar c)
          | c `elem` "*/" ->
            let (t, toks'') = term args $ accept toks'
             in (op c f t, toks'')
        _ -> (f, toks')
factor args toks =
  case lookAhead toks of
    TInt i -> (Imm i, accept toks)
    TStr s -> (Arg $ fromJust $ elemIndex s args, accept toks)
    TChar '(' ->
      let (expr, toks') = expression args $ accept toks
       in if lookAhead toks' /= TChar ')'
            then error "Missing right parenthesis"
            else (expr, accept toks')
    _ -> error $ "Parse error on token: " ++ show toks

parse :: [Token] -> AST
parse xs =
  let (args, xs') = argumemts xs
   in fst $ expression args xs'

pass1 :: String -> AST
pass1 = parse . tokenize

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

imI, arI :: Int -> String
imI n = "IM " ++ show n -- load the constant value n into R0
arI n = "AR " ++ show n -- load the n-th input argument into R0

swI, puI, poI, adI, suI, muI, diI :: String
swI = "SW" -- swap R0 and R1
puI = "PU" -- push R0 onto the stack
poI = "PO" -- pop the top value off of the stack into R0
adI = "AD" -- add R1 to R0 and put the result in R0
suI = "SU" -- subtract R1 from R0 and put the result in R0
muI = "MU" -- multiply R0 by R1 and put the result in R0
diI = "DI" -- divide R0 by R1 and put the result in R0

pass3 :: AST -> [String]
pass3 ast = undefined
