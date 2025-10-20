type Dict = [String]

main :: IO ()
main = do
  dict <- readDict
  text <- getContents
  putStr (spellCheck dict text)

readDict :: IO Dict
readDict = do
  txt <- readFile "/usr/share/dict/words"
  return (words txt)

checkWord :: Dict -> String -> String
checkWord dict word
  | word `elem` dict = word
  | otherwise = "\ESC[7m" ++ word ++ "\ESC[0m"

spellCheck :: Dict -> String -> String
spellCheck dict txt = unwords (map (checkWord dict) (words txt))
