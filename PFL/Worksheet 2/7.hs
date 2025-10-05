import Test.QuickCheck

median1 :: (Ord a) => a -> a -> a -> a
median1 x y z
  | x >= y && x <= z = x
  | x >= z && x <= y = x
  | y >= x && y <= z = y
  | y >= z && y <= x = y
  | otherwise = z

median2 :: (Num a, Ord a) => a -> a -> a -> a
median2 x y z = x + y + z - (x `max` y `max` z) - (x `min` y `min` z)

propMedian :: (Show a, Ord a, Num a) => a -> a -> a -> Property
propMedian x y z = median1 x y z === median2 x y z
