checkTriangle :: (Ord a, Num a) => a -> a -> a -> Bool
checkTriangle a b c = (a + b > c) && (a + c > b) && (b + c > a)
