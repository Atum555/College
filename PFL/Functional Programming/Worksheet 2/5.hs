safeTail :: [a] -> [a]
safeTail [] = []
safeTail xs = tail xs

-- >>> safeTail []
-- >>> safeTail [1,2,3]
-- >>> safeTail "atum"
-- []
-- [2,3]
-- "tum"
