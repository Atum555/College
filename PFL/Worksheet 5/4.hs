import Data.List (sort)

data Set a
  = Empty
  | Node a (Set a) (Set a)

empty :: Set a
empty = Empty

insert :: (Ord a) => a -> Set a -> Set a
insert x Empty = Node x Empty Empty
insert x (Node y left right)
  | x < y = Node y (insert x left) right
  | x > y = Node y left (insert x right)
  | otherwise = Node y left right

member :: (Ord a) => a -> Set a -> Bool
member x Empty = False
member x (Node y left right)
  | x == y = True
  | x < y = member x left
  | otherwise = member x right

fromList :: (Ord a) => [a] -> Set a
fromList xs = build (sort xs)
  where
    build [] = Empty
    build xs = Node x (build xs') (build xs'')
      where
        k = length xs `div` 2
        xs' = take k xs
        x : xs'' = drop k xs

----------------------------------
-- Exercise Code
----------------------------------

size :: Set a -> Int
size Empty = 0
size (Node _ l r) = 1 + size l + size r

height :: Set a -> Int
height Empty = 0
height (Node _ l r) = 1 + max (height l) (height r)

set1 :: Set Integer
set1 = foldr insert empty [1 .. 1000]

set2 :: Set Integer
set2 = fromList [1 .. 1000]

-- >>> size set1
-- >>> size set2
-- >>> height set1
-- >>> height set2
-- 1000
-- 1000
-- 1000
-- 10
