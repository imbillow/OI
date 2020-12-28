module UnlimitedGameOfLife where

import Data.List

pad :: [[Int]] -> [[Int]]
pad xs =
  let m = length xs
      n = length $ head xs
      add n xs =
        let l = replicate n 0
         in l : xs ++ [l]
   in transpose $ add (m + 2) $ transpose $ add n xs

neighbours y x xs cell =
  subtract cell $
    sum $
      concatMap (take nx . drop (max 0 $ x -1)) $
        take ny $ drop (max 0 $ y - 1) xs
  where
    nx = min (length (head xs) -1) (x + 1) - max 0 (x - 1) + 1
    ny = min (length xs -1) (y + 1) - max 0 (y - 1) + 1

rmZero :: [[Int]] -> [[Int]]
rmZero = transpose . rm . transpose . rm
  where
    zeros = all (== 0)
    rm = dropWhileEnd zeros . dropWhile zeros

getGeneration :: [[Int]] -> Int -> [[Int]]
getGeneration xs i
  | i <= 0 || null xs || null (head xs) = xs
  | otherwise = getGeneration mat $ i - 1
  where
    xs' = pad xs
    m = length xs'
    n = length (head xs')
    mat = rmZero [[f y x | x <- [0 .. n - 1]] | y <- [0 .. m - 1]]
    f y x =
      case (cell, neighbours y x xs' cell) of
        (1, 2) -> 1
        (_, 3) -> 1
        _ -> 0
      where
        cell = xs' !! y !! x

gliders :: [[[Int]]]
gliders =
  [ [ [1, 0, 0],
      [0, 1, 1],
      [1, 1, 0]
    ],
    [ [0, 1, 0],
      [0, 0, 1],
      [1, 1, 1]
    ],
    [ [1, 0, 1],
      [0, 1, 1],
      [0, 1, 0]
    ],
    [ [0, 0, 1],
      [1, 0, 1],
      [0, 1, 1]
    ]
  ]

twoGliders :: [[[Int]]]
twoGliders =
  [ [ [1, 1, 1, 0, 0, 0, 1, 0],
      [1, 0, 0, 0, 0, 0, 0, 1],
      [0, 1, 0, 0, 0, 1, 1, 1]
    ],
    [ [1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1]
    ]
  ]
