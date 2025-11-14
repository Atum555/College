short :: [a] -> Bool
short xs = length xs < 3

-- >>> short "1"
-- >>> short "12"
-- >>> short "123"
-- >>> short "1234"
-- True
-- True
-- False
-- False

short2 :: [a] -> Bool
short2 (x1 : x2 : x3 : _) = False
short2 (x1 : _) = True

-- >>> short2 "1"
-- >>> short2 "12"
-- >>> short2 "123"
-- >>> short2 "1234"
-- True
-- True
-- False
-- False
