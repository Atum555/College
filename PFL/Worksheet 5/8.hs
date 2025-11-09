booleans :: Int -> [[Bool]]
booleans 0 = [[]]
booleans n = [b : bs | b <- [False, True], bs <- booleans (n - 1)]

-- booleans n = map (False :) (booleans (n - 1)) ++ map (True :) (booleans (n - 1))

-- >>> booleans 1
-- >>> booleans 2
-- >>> booleans 3
-- [[False],[True]]
-- [[False,False],[False,True],[True,False],[True,True]]
-- [[False,False,False],[False,False,True],[False,True,False],[False,True,True],[True,False,False],[True,False,True],[True,True,False],[True,True,True]]
