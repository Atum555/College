isPrimeFast :: Integer -> Bool
isPrimeFast n = all (\i -> n `mod` i /= 0) [2 .. floor (sqrt (fromInteger n))]

-- >>> isPrimeFast 1
-- >>> isPrimeFast 2
-- >>> isPrimeFast 3
-- >>> isPrimeFast 5
-- >>> isPrimeFast 10
-- >>> isPrimeFast 13
-- >>> isPrimeFast 15
-- >>> isPrimeFast 17
-- >>> isPrimeFast 120
-- True
-- True
-- True
-- True
-- False
-- True
-- False
-- True
-- False
