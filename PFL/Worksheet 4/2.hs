primes :: [Integer]
primes = sieve [2 ..]

sieve :: [Integer] -> [Integer]
sieve (p : xs) = p : sieve [x | x <- xs, x `mod` p /= 0]

twinPrimes :: [(Integer, Integer)]
twinPrimes = [(a, b) | (a, b) <- zip primes (drop 1 primes), b == a + 2]

-- >>> take 10 twinPrimes
-- [(3,5),(5,7),(11,13),(17,19),(29,31),(41,43),(59,61),(71,73),(101,103),(107,109)]
