fromBits :: [Int] -> Int
fromBits = foldl (\n b -> n * 2 + b) 0

-- >>> fromBits [0]
-- >>> fromBits [1]
-- >>> fromBits [1,0]
-- >>> fromBits [1,1,0]
-- >>> fromBits [0,1,1,0]
-- >>> fromBits [1,1,0,1]
-- >>> fromBits [1,0,1,1,0]
-- 0
-- 1
-- 2
-- 6
-- 6
-- 13
-- 22
