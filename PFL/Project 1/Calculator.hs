module Main where

import Data.Char
import Parsing

----------------------------------------------------------------
-- Data Types
----------------------------------------------------------------

data Expr
  = Num Integer
  | Add Expr Expr
  | Mul Expr Expr
  deriving (Show)

----------------------------------------------------------------
-- Evaluator Function
----------------------------------------------------------------

eval :: Expr -> Integer
eval (Num n) = n
eval (Add e1 e2) = eval e1 + eval e2
eval (Mul e1 e2) = eval e1 * eval e2

----------------------------------------------------------------
-- Parsers
----------------------------------------------------------------

-- | a parser for expressions
-- Grammar rules:
--
-- expr ::= term exprCont
-- exprCont ::= '+' term exprCont | epsilon

-- term ::= factor termCont
-- termCont ::= '*' factor termCont | epsilon

-- factor ::= natural | '(' expr ')'

expr :: Parser Expr
expr = do
  t <- term
  exprCont t

exprCont :: Expr -> Parser Expr
exprCont acc =
  do
    char '+'
    t <- term
    exprCont (Add acc t)
    <|> return acc

term :: Parser Expr
term = do
  f <- factor
  termCont f

termCont :: Expr -> Parser Expr
termCont acc =
  do
    char '*'
    f <- factor
    termCont (Mul acc f)
    <|> return acc

factor :: Parser Expr
factor =
  do
    n <- natural
    return (Num n)
    <|> do
      char '('
      e <- expr
      char ')'
      return e

natural :: Parser Integer
natural = do
  xs <- many1 (satisfy isDigit)
  return (read xs)

----------------------------------------------------------------
-- Main Loop
----------------------------------------------------------------

main :: IO ()
main =
  do
    txt <- getContents
    calculator (lines txt)

-- | read-eval-print loop
calculator :: [String] -> IO ()
calculator [] = return ()
calculator (l : ls) = do
  putStrLn (evaluate l)
  calculator ls

-- | evaluate a single expression
evaluate :: String -> String
evaluate txt =
  case parse expr txt of
    [(tree, "")] -> show (eval tree)
    _ -> "parse error; try again"
