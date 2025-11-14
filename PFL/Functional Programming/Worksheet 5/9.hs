type Name = Char -- ’x’, ’y’, ’z’, etc.

type Env = [(Name, Bool)]

booleans :: Int -> [[Bool]]
booleans 0 = [[]]
booleans n = [b : bs | b <- [False, True], bs <- booleans (n - 1)]

environments :: [Name] -> [Env]
environments names = map (zip names) (booleans (length names))

-- >>> environments "a"
-- >>> environments "ab"
-- >>> environments "abc"
-- >>> environments "abcd"
-- [[('a',False)],[('a',True)]]
-- [[('a',False),('b',False)],[('a',False),('b',True)],[('a',True),('b',False)],[('a',True),('b',True)]]
-- [[('a',False),('b',False),('c',False)],[('a',False),('b',False),('c',True)],[('a',False),('b',True),('c',False)],[('a',False),('b',True),('c',True)],[('a',True),('b',False),('c',False)],[('a',True),('b',False),('c',True)],[('a',True),('b',True),('c',False)],[('a',True),('b',True),('c',True)]]
-- [[('a',False),('b',False),('c',False),('d',False)],[('a',False),('b',False),('c',False),('d',True)],[('a',False),('b',False),('c',True),('d',False)],[('a',False),('b',False),('c',True),('d',True)],[('a',False),('b',True),('c',False),('d',False)],[('a',False),('b',True),('c',False),('d',True)],[('a',False),('b',True),('c',True),('d',False)],[('a',False),('b',True),('c',True),('d',True)],[('a',True),('b',False),('c',False),('d',False)],[('a',True),('b',False),('c',False),('d',True)],[('a',True),('b',False),('c',True),('d',False)],[('a',True),('b',False),('c',True),('d',True)],[('a',True),('b',True),('c',False),('d',False)],[('a',True),('b',True),('c',False),('d',True)],[('a',True),('b',True),('c',True),('d',False)],[('a',True),('b',True),('c',True),('d',True)]]
