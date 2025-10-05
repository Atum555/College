factorial :: (Num a, Enum a) => a -> a
factorial x = product [1 .. x]

-- >>> factorial 3
-- >>> factorial 5
-- 6
-- 120

binom :: (Integral a) => a -> a -> a
binom n k = div (factorial n) (factorial k * factorial (n - k))

-- >>> binom 3 1
-- >>> binom 4 2
-- 3
-- 6

pascal :: (Integral a) => a -> [[a]]
pascal n = [[binom x y | y <- [0 .. x]] | x <- [0 .. n]]

-- >>> pascal 0
-- >>> pascal 1
-- >>> pascal 3
-- >>> pascal 7
-- [[1]]
-- [[1],[1,1]]
-- [[1],[1,1],[1,2,1],[1,3,3,1]]
-- [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1],[1,5,10,10,5,1],[1,6,15,20,15,6,1],[1,7,21,35,35,21,7,1]]
