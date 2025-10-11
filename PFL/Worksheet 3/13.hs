group :: (Eq a) => [a] -> [[a]]
group [] = []
group (x : xs) = (x : takeWhile (== x) xs) : group (dropWhile (== x) xs)

-- >>> group "AAABBACCC"
-- >>> group "AAABBACCCHHSDCC"
-- >>> group [1,2,2,2,1,1,3,3,4,2,4,4]
-- ["AAA","BB","A","CCC"]
-- ["AAA","BB","A","CCC","HH","S","D","CC"]
-- [[1],[2,2,2],[1,1],[3,3],[4],[2],[4,4]]
