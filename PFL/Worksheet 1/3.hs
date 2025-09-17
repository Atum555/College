second :: [a] -> a
-- second x = head (drop 1 x)
second x = x !! 1

myLast :: [a] -> a
-- myLast x = head (reverse x)
myLast x = x !! (length x - 1)

myInit :: [a] -> [a]
myInit x = reverse (tail (reverse x))

myMiddle :: [a] -> a
myMiddle x = x !! div (length x) 2

isPalindrome :: (Eq a) => [a] -> Bool
-- isPalindrome xs = xs == reverse xs
isPalindrome x
  | length x <= 1 = True
  | head x == last x = isPalindrome $ init $ tail x
  | otherwise = False
