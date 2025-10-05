propDivs :: (Integral a) => a -> [a]
propDivs x = [y | y <- [1 .. x - 1], x `mod` y == 0]

-- >>> propDivs 10
-- >>> propDivs 12
-- >>> propDivs 13
-- >>> propDivs 15
-- >>> propDivs 17
-- >>> propDivs 120
-- [1,2,5]
-- [1,2,3,4,6]
-- [1]
-- [1,3,5]
-- [1]
-- [1,2,3,4,5,6,8,10,12,15,20,24,30,40,60]
