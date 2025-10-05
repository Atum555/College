max3 :: (Ord a) => a -> a -> a -> a
max3 x y z
  | x > y && x > z = x
  | y > z = y
  | otherwise = z

min3 :: (Ord a) => a -> a -> a -> a
min3 x y z
  | x < y && x < z = x
  | y < z = y
  | otherwise = z

-- >>> max3 1 2 3
-- >>> max3 1 3 2
-- >>> max3 3 1 2
-- >>> min3 1 2 3
-- >>> min3 2 1 3
-- >>> min3 2 3 1
-- 3
-- 3
-- 3
-- 1
-- 1
-- 1

max3_2 :: (Ord a) => a -> a -> a -> a
max3_2 x y z = x `max` y `max` z

min3_2 :: (Ord a) => a -> a -> a -> a
min3_2 x y z = x `min` y `min` z

-- >>> max3_2 1 2 3
-- >>> max3_2 1 3 2
-- >>> max3_2 3 1 2
-- >>> min3_2 1 2 3
-- >>> min3_2 2 1 3
-- >>> min3_2 2 3 1
-- 3
-- 3
-- 3
-- 1
-- 1
-- 1
