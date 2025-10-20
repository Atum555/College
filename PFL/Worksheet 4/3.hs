hamming :: [Integer]
hamming =
  [ 2 ^ i * 3 ^ j * 5 ^ k
    | n <- [0 ..],
      i <- [0 .. n],
      j <- [0 .. n - i],
      let k = n - i - j
  ]

-- >>> take 20 hamming
-- [1,5,3,2,25,15,9,10,6,4,125,75,45,27,50,30,18,20,12,8]
