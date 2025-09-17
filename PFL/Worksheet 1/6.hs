a :: (Char, Char)
a = ('a', '2')

b :: (Char, Integer)
b = ('b', 1)

c :: [Char]
c = ['a', 'b', 'c']

d :: Bool
d = 1 + 2 == 4

e :: Bool -> Bool
e = not

f :: Double -> Double
f = sqrt

g :: [Double -> Double]
g = [sqrt, sin, cos]

h :: [[a] -> [a]]
h = [tail, init, reverse]

i :: ([Bool], [Bool])
i = ([False, True], [True, False])

j :: [(Bool, Bool)]
j = [(False, True), (True, False)]
