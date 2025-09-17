leftHalf x = take (div (length x) 2) x

rightHalf x = drop (div (length x) 2) x

main = do
  print $ leftHalf [1 .. 11]
  print $ rightHalf [1 .. 11]
  putStr "\n"
  print $ leftHalf [1 .. 1]
  print $ rightHalf [1 .. 1]
  putStr "\n"
  print $ leftHalf [1 .. 0]
  print $ rightHalf [1 .. 0]
