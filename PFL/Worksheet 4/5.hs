import Data.Char (chr, isAlpha, isAscii, isAsciiLower, isLetter, ord)
import Test.QuickCheck

-- Program entry
main :: IO ()
main = do
  putStrLn "Enter text to encode with ROT13 (type 'exit' to quit):"
  loop

-- Main loop
loop :: IO ()
loop = do
  txt <- getLine
  if txt == "exit"
    then putStrLn "Goodbye!"
    else do
      putStrLn (rot13 txt)
      loop

-- ROT13 function
rot13 :: String -> String
rot13 [] = []
rot13 (x : xs)
  | isAscii x && isAlpha x = mapping x : rot13 xs
  | otherwise = x : rot13 xs
  where
    mapping :: Char -> Char
    mapping c
      | isAsciiLower c = chr ((ord c - ord 'a' + 13) `mod` 26 + ord 'a')
      | otherwise = chr ((ord c - ord 'A' + 13) `mod` 26 + ord 'A')

-- Test
propRot13 :: String -> Property
propRot13 x = rot13 (rot13 x) === x
