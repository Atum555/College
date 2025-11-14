import Data.List (sort)

data Set a
  = Empty
  | Node a (Set a) (Set a)

empty :: Set a
empty = Empty

insert :: (Ord a) => a -> Set a -> Set a
insert x Empty = Node x Empty Empty
insert x (Node y left right)
  | x < y = Node y (insert x left) right
  | x > y = Node y left (insert x right)
  | otherwise = Node y left right

member :: (Ord a) => a -> Set a -> Bool
member x Empty = False
member x (Node y left right)
  | x == y = True
  | x < y = member x left
  | otherwise = member x right

fromList :: (Ord a) => [a] -> Set a
fromList xs = build (sort xs)
  where
    build [] = Empty
    build xs = Node x (build xs') (build xs'')
      where
        k = length xs `div` 2
        xs' = take k xs
        x : xs'' = drop k xs

----------------------------------
-- Exercise Code
----------------------------------

main :: IO ()
main = do
  dict <- readDict
  let set = fromList dict
  text <- getContents
  putStr (spellCheck set text)

readDict :: IO [String]
readDict = do
  txt <- readFile "/usr/share/dict/words"
  return (words txt)

checkWord :: Set String -> String -> String
checkWord dict word
  | word `member` dict = word
  | otherwise = "\ESC[7m" ++ word ++ "\ESC[0m"

spellCheck :: Set String -> String -> String
spellCheck dict txt = unwords (map (checkWord dict) (words txt))
