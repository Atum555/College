toBits :: Int -> [Int]
toBits n = reverse (bits n)
  where
    bits 0 = [0]
    bits 1 = [1]
    bits n = n `mod` 2 : bits (n `div` 2)

-- >>> toBits 1
-- >>> toBits 2
-- >>> toBits 3
-- >>> toBits 4
-- >>> toBits 5
-- >>> toBits 6
-- >>> toBits 7
-- >>> toBits 8
-- >>> toBits 127
-- >>> toBits 128
-- >>> toBits 6541
-- [1]
-- [1,0]
-- [1,1]
-- [1,0,0]
-- [1,0,1]
-- [1,1,0]
-- [1,1,1]
-- [1,0,0,0]
-- [1,1,1,1,1,1,1]
-- [1,0,0,0,0,0,0,0]
-- [1,1,0,0,1,1,0,0,0,1,1,0,1]
