merge :: (Ord a) => [a] -> [a] -> [a]
merge x [] = x
merge [] x = x
merge (x : xs) (y : ys)
  | x <= y = x : merge xs (y : ys)
  | otherwise = y : merge (x : xs) ys

-- >>> merge [] []
-- >>> merge [] [1]
-- >>> merge [1] []
-- >>> merge [1,2] [2]
-- >>> merge [1,2,3] [2]
-- >>> merge [1,2,3,9] [2,4,5]
-- []
-- [1]
-- [1]
-- [1,2,2]
-- [1,2,2,3]
-- [1,2,2,3,4,5,9]

msort [] = []
msort [x] = [x]
msort xs = merge (msort first) (msort second)
  where
    first = take (length xs `div` 2) xs
    second = drop (length xs `div` 2) xs

-- >>> msort []
-- >>> msort [1,2,3]
-- >>> msort [3,2,1]
-- >>> msort [3,2,1,4]
-- >>> msort [3,2,1,4,0]
-- []
-- [1,2,3]
-- [1,2,3]
-- [1,2,3,4]
-- [0,1,2,3,4]
