myInsert :: (Ord t) => t -> [t] -> [t]
myInsert x [] = [x]
myInsert x (y : ys)
  | x < y = x : y : ys
  | otherwise = y : myInsert x ys

-- >>> myInsert 3 []
-- >>> myInsert 3 [1]
-- >>> myInsert 3 [1,2]
-- >>> myInsert 3 [1,2,3]
-- >>> myInsert 3 [1,2,3,4]
-- >>> myInsert 3 [1,2,4]
-- >>> myInsert 3 [1,2,4,5]
-- [3]
-- [1,3]
-- [1,2,3]
-- [1,2,3,3]
-- [1,2,3,3,4]
-- [1,2,3,4]
-- [1,2,3,4,5]

isort :: (Ord a) => [a] -> [a]
isort [] = []
isort (x : xs) = myInsert x (isort xs)

-- >>> isort []
-- >>> isort [1,2,3]
-- >>> isort [3,2,1]
-- >>> isort [3,2,1,4]
-- >>> isort [3,2,1,4,0]
-- []
-- [1,2,3]
-- [1,2,3]
-- [1,2,3,4]
-- [0,1,2,3,4]
