propDivs :: (Integral a) => a -> [a]
propDivs x = [y | y <- [1 .. x - 1], x `mod` y == 0]

perfects :: (Integral a) => a -> [a]
perfects x = [y | y <- [1 .. x], sum (propDivs y) == y]

-- >>> perfects 500
-- [6,28,496]
