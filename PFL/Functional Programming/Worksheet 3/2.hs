leastDiv :: Int -> Int
leastDiv n = internalDiv 2
  where
    internalDiv i
      | i * i > n = n
      | n `mod` i == 0 = i
      | otherwise = internalDiv (i + 1)

-- >>> leastDiv 1
-- >>> leastDiv 2
-- >>> leastDiv 4
-- >>> leastDiv 5
-- >>> leastDiv 10
-- >>> leastDiv 13
-- >>> leastDiv 120
-- >>> leastDiv 127
-- 1
-- 2
-- 2
-- 5
-- 2
-- 13
-- 2
-- 127

isPrimeFast :: Int -> Bool
isPrimeFast n
  | n > 1 = leastDiv n == n
  | otherwise = False

-- >>> isPrimeFast 1
-- >>> isPrimeFast 2
-- >>> isPrimeFast 3
-- >>> isPrimeFast 4
-- >>> isPrimeFast 9
-- >>> isPrimeFast 13
-- >>> isPrimeFast 127
-- False
-- True
-- True
-- False
-- False
-- True
-- True
