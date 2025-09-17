incr :: Int -> Int
incr x = x + 1

triple :: Int -> Int
triple x = 3 * x

welcome :: String -> String
welcome name = "Hello, " ++ name ++ "!"

count :: String -> String
count str = show (length str) ++ " characters."

main :: IO ()
main = do
  print $ incr (triple 3)
  print $ triple (incr (3 + 1))
  print $ triple (incr 3 + 1)
  print $ triple (incr 3) + 1
  print $ welcome "Harry" ++ welcome "Potter"
  print $ welcome ("Harry" ++ " Potter")
  print $ welcome (welcome "Potter")
  print $ count "Expelliarmus!"
  print $ count (count "Expelliarmus!")
