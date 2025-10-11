myAppend :: [a] -> [a] -> [a]
myAppend [x] ys = x : ys
myAppend xs ys = foldr (:) ys xs

-- >>> myAppend [] []
-- >>> myAppend [] [1]
-- >>> myAppend [] [1,2]
-- >>> myAppend [1,2] []
-- >>> myAppend [1,2] [3,4]
-- []
-- [1]
-- [1,2]
-- [1,2]
-- [1,2,3,4]

myConcat :: [[a]] -> [a]
myConcat = foldr (++) []

-- >>> myConcat []
-- >>> myConcat [[]]
-- >>> myConcat [[1,2]]
-- >>> myConcat [[],[1,2]]
-- >>> myConcat [[],[1,2],[3,4]]
-- >>> myConcat [[],[1,2],[3,4],[]]
-- []
-- []
-- [1,2]
-- [1,2]
-- [1,2,3,4]
-- [1,2,3,4]

myReverseR :: [a] -> [a]
-- myReverseR = foldr (\a b -> b ++ [a]) []
myReverseR = foldr (:) []

-- >>> myReverseR []
-- >>> myReverseR [1]
-- >>> myReverseR [1,2]
-- >>> myReverseR [1,2,3]
-- []
-- [1]
-- [1,2]
-- [1,2,3]

myReverseL :: [a] -> [a]
myReverseL = foldl (flip (:)) []

-- >>> myReverseL []
-- >>> myReverseL [1]
-- >>> myReverseL [1,2]
-- >>> myReverseL [1,2,3]
-- []
-- [1]
-- [2,1]
-- [3,2,1]

myElem :: (Eq a) => a -> [a] -> Bool
myElem x = any (== x)

-- >>> myElem 3 []
-- >>> myElem 3 [1]
-- >>> myElem 3 [1,2]
-- >>> myElem 3 [1,2,3]
-- >>> myElem 3 [1,2,3,4]
-- False
-- False
-- False
-- True
-- True
