module Kata.GetToTheChoppa where

import Control.Monad
import Data.List
import Data.Maybe
import qualified Data.Set as S

type Pos = (Int, Int)

data Node = Passable | NotPassable deriving (Eq, Show)

type Grid = [[Node]]

type Path = [Pos]

shortestPath :: Grid -> Pos -> Pos -> Path
shortestPath g _ _ | null g || null (head g) = []
shortestPath g a b = fromJust $ visit S.empty [(a, [a])]
  where
    (w, h) = (length $ head g, length g)
    succsor (x, y) =
      filter
        ( \(x', y') ->
            (x' >= 0 && x' < w && y' >= 0 && y' < h)
              && (g !! y' !! x') == Passable
        )
        $ map
          (\(x', y') -> (x' + x, y' + y))
          [(-1, 0), (1, 0), (0, -1), (0, 1)]
    visit :: S.Set Pos -> [(Pos, Path)] -> Maybe Path
    visit _ pp
      | isJust path = fmap reverse path
      where
        path = lookup b pp
    visit visited pp =
      visit (S.union visited $ S.fromList (map fst pp)) $
        concatMap
          ( \(pos, path) ->
              map (\p -> (p, p : path)) $
                filter (`S.notMember` visited) $ succsor pos
          )
          pp

-- Convert a string representation into a grid
toGrid = map (map (\c -> if c == '1' then NotPassable else Passable)) . words

grid =
  "0000000000000000000000\n"
    ++ "S111111111111111110101\n"
    ++ "0000000000000000010101\n"
    ++ "1111111011110111010101\n"
    ++ "0110001000100011110101\n"
    ++ "0000101010101000000101\n"
    ++ "0111100010001111101101\n"
    ++ "0111111111111000100001\n"
    ++ "0100010001000000111111\n"
    ++ "0101010101010010000001\n"
    ++ "0101010101011110111101\n"
    ++ "00010001000110000011E1"
