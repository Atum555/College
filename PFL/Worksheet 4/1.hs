calcPi1 :: Int -> Double
calcPi1 n = foldr (\(value, op) acc -> acc `op` value) 0 (zip (take n [up / down | (up, down) <- map (4,) [1, 3 ..]]) (cycle [(+), (-)]))

calcPi1_2 :: Int -> Double
calcPi1_2 n = sum (take n [a / b | (a, b) <- zip (cycle [4, -4]) [1, 3 ..]])

calcPi2 :: Int -> Double
calcPi2 n = 3 + sum (take n [a / (b * (b + 1) * (b + 2)) | (a, b) <- zip (cycle [4, -4]) [2, 4 ..]])

-- >>> calcPi1 1000
-- >>> calcPi1 10000
-- >>> calcPi1 100000
-- >>> calcPi1 1000000
-- >>> calcPi2 1000
-- >>> calcPi2 10000
-- >>> calcPi2 100000
-- >>> calcPi2 1000000
-- 3.140592653839793
-- 3.1414926535900434
-- 3.1415826535897935
-- 3.1415916535897934
-- 3.1415926533405423
-- 3.1415926535895418
-- 3.1415926535897913
-- 3.1415926535897913
