toBits :: Int -> [Int]
toBits n = reverse (bits n)
  where
    bits 0 = [0]
    bits 1 = [1]
    bits n = n `mod` 2 : bits (n `div` 2)

fromBits :: [Int] -> Int
fromBits = getNumber 0
  where
    getNumber x [] = x
    getNumber x (y : ys) = getNumber (x * 2 + y) ys

-- >>> fromBits [0]
-- >>> fromBits [1]
-- >>> fromBits [1,0]
-- >>> fromBits [1,1,0]
-- >>> fromBits [0,1,1,0]
-- >>> fromBits [1,0,1,1,0]
-- 0
-- 1
-- 2
-- 6
-- 6
-- 22

-- >>> fromBits (toBits 1)
-- >>> fromBits (toBits 2)
-- >>> fromBits (toBits 3)
-- >>> fromBits (toBits 4)
-- >>> fromBits (toBits 5)
-- >>> fromBits (toBits 9)
-- >>> fromBits (toBits 12)
-- >>> fromBits (toBits 124)
-- >>> fromBits (toBits 124534)
-- 1
-- 2
-- 3
-- 4
-- 5
-- 9
-- 12
-- 124
-- 124534
