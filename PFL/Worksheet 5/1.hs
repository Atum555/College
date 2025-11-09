data List a = Empty | Cons a (List a)
  deriving (Show)

toList :: [a] -> List a
toList = foldr Cons Empty

-- Different Implementation
-- toList [] = Empty
-- toList (x:xs) = Cons x (toList xs)

-- >>> toList [1,2,3,4]
-- Cons 1 (Cons 2 (Cons 3 (Cons 4 Empty)))

fromList :: List a -> [a]
fromList Empty = []
fromList (Cons x xs) = x : fromList xs

-- >>> fromList (Cons 1 (Cons 2 (Cons 3 (Cons 4 Empty))))
-- [1,2,3,4]

-- >>> fromList (toList [1,2,2,3,4,4,5,6])
-- [1,2,2,3,4,4,5,6]
