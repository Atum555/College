type AWord = String

type Line = [AWord]

type Paragraph = [Line]

-- Program entry
main :: IO ()
main = do
  putStrLn "Enter words:"
  txt <- getLine
  let ws = words txt
  let paragraph = fillWords 70 ws
  putStr (formatParagraph paragraph)

formatParagraph :: Paragraph -> String
formatParagraph = unlines . map unwords

fillWords :: Int -> [AWord] -> Paragraph
fillWords _ [] = []
fillWords maxWidth (w : ws) = fillWords' [w] ws
  where
    fillWords' :: Line -> [AWord] -> Paragraph
    fillWords' currentLine [] = [reverse currentLine]
    fillWords' currentLine (word : rest)
      | lineWidth currentLine + 1 + length word <= maxWidth = fillWords' (word : currentLine) rest
      | otherwise = reverse currentLine : fillWords' [] (word : rest)

    lineWidth :: Line -> Int
    lineWidth line = sum (map length line) + length line - 1

-- >>> fillWords 10 []
-- >>> fillWords 10 ["abc"]
-- >>> fillWords 10 ["abc", "abc", "abc", "abc", "abc", "abc", "abc", "abc", "abc", "abc", "abc"]
-- []
-- [["abc"]]
-- [["abc","abc"],["abc","abc"],["abc","abc"],["abc","abc"],["abc","abc"],["abc"]]
