second :: [a] -> a
second xs = head (tail xs)

swap :: (a, b) -> (b, a)
swap (x, y) = (y, x)

pair :: a -> (a, a)
pair x = (x, x)

double :: (Num a) => a -> a
double x = 2 * x

half :: (Fractional a) => a -> a
half x = x / 2

average :: (Fractional a) => a -> a -> a
average x y = (x + y) / 2

isLower :: Char -> Bool
isLower x = x >= 'a' && x <= 'z'

inRange :: (Ord a) => a -> a -> a -> Bool
inRange x lo hi = x >= lo && x <= hi

isPalindrome :: (Eq a) => [a] -> Bool
isPalindrome xs = xs == reverse xs

twice :: (t -> t) -> t -> t
twice f x = f (f x)
