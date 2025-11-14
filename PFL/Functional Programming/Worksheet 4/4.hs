merge :: (Ord a) => [a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x : xs) (y : ys)
  | x < y = x : merge xs (y : ys)
  | x > y = y : merge (x : xs) ys
  | otherwise = x : merge xs ys

-- >>> merge [] []
-- >>> merge [1,2] []
-- >>> merge [] [1,2]
-- >>> merge [1,3] [1,2]
-- >>> merge [1,3,4] [1,2,5]
-- []
-- [1,2]
-- [1,2]
-- [1,2,3]
-- [1,2,3,4,5]

hamming :: [Integer]
hamming = 1 : merge (map (2 *) hamming) (merge (map (3 *) hamming) (map (5 *) hamming))

-- >>> take 35 hamming
-- [1,2,3,4,5,6,8,9,10,12,15,16,18,20,24,25,27,30,32,36,40,45,48,50,54,60,64,72,75,80,81,90,96,100,108]
