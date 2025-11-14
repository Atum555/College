pythagorical :: (Eq a, Num a) => a -> a -> a -> Bool
pythagorical x y z = x * x + y * y == z * z

pyths :: (Num c, Enum c, Eq c) => c -> [(c, c, c)]
pyths x = [(a, b, c) | a <- [1 .. x], b <- [1 .. x], c <- [1 .. x], pythagorical a b c]

-- >>> pyths 10
-- >>> pyths 20
-- [(3,4,5),(4,3,5),(6,8,10),(8,6,10)]
-- [(3,4,5),(4,3,5),(5,12,13),(6,8,10),(8,6,10),(8,15,17),(9,12,15),(12,5,13),(12,9,15),(12,16,20),(15,8,17),(16,12,20)]
