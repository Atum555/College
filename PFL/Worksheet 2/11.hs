divisors :: (Integral a) => a -> [a]
divisors x = [y | y <- [1 .. x], x `mod` y == 0]

isPrime :: (Integral a) => a -> Bool
isPrime x = divisors x == [1, x]

-- >>> isPrime 1
-- >>> isPrime 2
-- >>> isPrime 3
-- >>> isPrime 4
-- >>> isPrime 5
-- >>> isPrime 9
-- >>> isPrime 10
-- >>> isPrime 13
-- >>> isPrime 120
-- >>> isPrime 127
-- False
-- True
-- True
-- False
-- True
-- False
-- False
-- True
-- False
-- True
