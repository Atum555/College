nub :: (Eq a) => [a] -> [a]
nub [] = []
nub (x : xs) = x : nub (no_x xs)
  where
    no_x [] = []
    no_x (y : ys)
      | x == y = no_x ys
      | otherwise = y : no_x ys

-- >>> nub "banana"
-- >>> nub "123"
-- >>> nub "123321"
-- "ban"
-- "123"
-- "123"
