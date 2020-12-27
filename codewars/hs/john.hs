ann' :: [Integer]
ann' = 1 : [i - john' !! fromInteger t | i <- [1 ..], let t = ann' !! fromInteger (i -1)]

john' :: [Integer]
john' = 0 : [i - ann' !! fromInteger t | i <- [1 ..], let t = john' !! fromInteger (i -1)]

ann :: Int -> [Integer]
ann n = take n ann'

john :: Int -> [Integer]
john n = take n john'

sumAnn :: Int -> Integer
sumAnn = sum . ann

sumJohn :: Int -> Integer
sumJohn = sum . john
