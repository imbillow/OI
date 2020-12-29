module Parens where

import Control.Lens
import Data.List

balancedParens :: Int -> [String]
balancedParens x = parens $ f' !! x
  where
    p = [replicate n '(' ++ replicate n ')' | n <- [0 ..]]
    parens = map (concatMap (p !!))

f' :: [[[Int]]]
f' = [[0]] : iterate (nub . concatMap add1) [[1]]

add1 :: [Int] -> [[Int]]
add1 xs =
  [ xs & ix i %~ (+ 1)
    | i <- inds
  ]
    ++ [ y ++ [1] ++ ys
         | i <- inds,
           let (y, ys) = splitAt i xs
       ]
  where
    inds = [0 .. length xs -1]
