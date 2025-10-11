intercalate :: a -> [a] -> [[a]]
intercalate x [] = [[x]]
intercalate x ys = [put_on i ys | i <- [0 .. length ys]]
  where
    put_on _ [] = [x]
    put_on i (a : as)
      | i == 0 = x : a : as
      | otherwise = a : put_on (i - 1) as

-- >>> intercalate '_' ""
-- >>> intercalate '_' "a"
-- >>> intercalate '_' "ab"
-- >>> intercalate '_' "abc"
-- ["_"]
-- ["_a","a_"]
-- ["_ab","a_b","ab_"]
-- ["_abc","a_bc","ab_c","abc_"]

permutations :: [a] -> [[a]]
permutations = foldr (\x xss -> concat [intercalate x xs | xs <- xss]) [[]]

-- >>> permutations "a"
-- >>> permutations "ab"
-- >>> permutations "abc"
-- >>> permutations "abcd"
-- ["a"]
-- ["ab","ba"]
-- ["abc","bac","bca","acb","cab","cba"]
-- ["abcd","bacd","bcad","bcda","acbd","cabd","cbad","cbda","acdb","cadb","cdab","cdba","abdc","badc","bdac","bdca","adbc","dabc","dbac","dbca","adcb","dacb","dcab","dcba"]
