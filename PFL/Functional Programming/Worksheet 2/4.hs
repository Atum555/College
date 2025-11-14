myXOR :: Bool -> Bool -> Bool
myXOR False False = False
myXOR False True = True
myXOR True False = True
myXOR True True = False

-- >>> myXOR False False
-- >>> myXOR False True
-- >>> myXOR True False
-- >>> myXOR True True
-- False
-- True
-- True
-- False
