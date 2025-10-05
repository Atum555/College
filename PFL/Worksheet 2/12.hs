myConcat :: [[a]] -> [a]
myConcat xss = [x | xs <- xss, x <- xs]

-- >>> concat [[1,2,3], [4,5]]
-- >>> myConcat [[1,2,3], [4,5]]
-- [1,2,3,4,5]
-- [1,2,3,4,5]

myReplicate :: (Num t, Enum t) => t -> a -> [a]
myReplicate n x = [x | _ <- [1 .. n]]

-- >>> replicate 0 False
-- >>> replicate (-1) False
-- >>> replicate 4 False
-- >>> myReplicate 0 False
-- >>> myReplicate (-1) False
-- >>> myReplicate 4 False
-- []
-- []
-- [False,False,False,False]
-- []
-- []
-- [False,False,False,False]

myIndex :: (Num a1, Enum a1, Eq a1) => [a2] -> a1 -> a2
myIndex xs i = head [x | (x, ii) <- zip xs [0 ..], ii == i]

-- >>>  [1,2,3] !! 2
-- >>> myIndex [1,2,3] (2)
-- 3
-- 3
