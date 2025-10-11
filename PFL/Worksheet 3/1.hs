myAnd :: [Bool] -> Bool
myAnd [] = True
myAnd (x : xs) = x && myAnd xs

-- >>> myAnd []
-- >>> myAnd [False, False]
-- >>> myAnd [False, True]
-- >>> myAnd [True, True]
-- True
-- False
-- False
-- True

myOr :: [Bool] -> Bool
myOr [] = False
myOr (x : xs) = x || myOr xs

-- >>> myOr []
-- >>> myOr [False, False]
-- >>> myOr [False, True]
-- >>> myOr [True, True]
-- False
-- False
-- True
-- True

myConcat :: [[a]] -> [a]
myConcat [] = []
myConcat (xs : xss) = xs ++ myConcat xss

-- >>> myConcat []
-- >>> myConcat [[]]
-- >>> myConcat [[1,2],[]]
-- >>> myConcat [[1,2],[3,4]]
-- []
-- []
-- [1,2]
-- [1,2,3,4]

myReplicate :: Int -> a -> [a]
myReplicate 0 _ = []
myReplicate n x = x : myReplicate (n - 1) x

-- >>> myReplicate 0 "atum"
-- >>> myReplicate 1 "atum"
-- >>> myReplicate 3 "atum"
-- []
-- ["atum"]
-- ["atum","atum","atum"]

myIndex :: [a] -> Int -> a
myIndex (x : xs) 0 = x
myIndex (x : xs) n = xs `myIndex` (n - 1)

-- >>> myIndex [1,2,3] 0
-- >>> myIndex [1,2,3] 1
-- >>> myIndex [1,2,3] 2
-- 1
-- 2
-- 3

myElem :: (Eq t) => t -> [t] -> Bool
myElem e [] = False
myElem e (x : xs) = e == x || myElem e xs

-- >>> myElem 1 [1,2,3]
-- >>> myElem 2 [1,2,3]
-- >>> myElem 0 [1,2,3]
-- True
-- True
-- False
