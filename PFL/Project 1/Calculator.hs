module Main where

import Data.Char
import Parsing

----------------------------------------------------------------
-- Data Types
----------------------------------------------------------------

type Name = String

type Env = [(Name, Integer)]

data Expr
  = Num Integer
  | Var Name
  | Add Expr Expr
  | Sub Expr Expr
  | Mul Expr Expr
  | Div Expr Expr
  | Mod Expr Expr
  deriving (Show)

data Command = Assign Name Expr | Expr Expr
  deriving (Show)

----------------------------------------------------------------
-- Function to Update Env
----------------------------------------------------------------

updateEnv :: Name -> Integer -> Env -> Env
updateEnv name value [] = [(name, value)]
updateEnv name value ((n, v) : rest)
  | n == name = (name, value) : rest
  | otherwise = (n, v) : updateEnv name value rest

----------------------------------------------------------------
-- Evaluator Function
----------------------------------------------------------------

eval :: Expr -> Env -> Integer
eval (Num n) _ = n
eval (Var v) env = case lookup v env of
  Just n -> n
  Nothing -> error "undefined variable"
eval (Add e1 e2) env = eval e1 env + eval e2 env
eval (Sub e1 e2) env = eval e1 env - eval e2 env
eval (Mul e1 e2) env = eval e1 env * eval e2 env
eval (Div e1 e2) env = eval e1 env `div` eval e2 env
eval (Mod e1 e2) env = eval e1 env `mod` eval e2 env

----------------------------------------------------------------
-- Parsers
----------------------------------------------------------------

-- | a parser for expressions
-- Grammar rules:
--
-- expr ::= term exprCont
-- exprCont ::= '+' term exprCont | '-' term exprCont | epsilon

-- term ::= factor termCont
-- termCont ::= '*' factor termCont | '/' factor termCont | '%' factor termCont | epsilon

-- factor ::= variable | natural | '(' expr ')'

-- command ::= variable '=' expr | expr

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
    <|> do
      char '-'
      t <- term
      exprCont (Sub acc t)
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
    <|> do
      char '/'
      f <- factor
      termCont (Div acc f)
    <|> do
      char '%'
      f <- factor
      termCont (Mod acc f)
    <|> return acc

factor :: Parser Expr
factor =
  do
    v <- variable
    return (Var v)
    <|> do
      n <- natural
      return (Num n)
    <|> do
      char '('
      e <- expr
      char ')'
      return e

command :: Parser Command
command =
  do
    v <- variable
    char '='
    e <- expr
    return (Assign v e)
    <|> do
      e <- expr
      return (Expr e)

natural :: Parser Integer
natural = do
  xs <- many1 (satisfy isDigit)
  return (read xs)

variable :: Parser String
variable = do
  many1 (satisfy isLetter)

----------------------------------------------------------------
-- Main Loop
----------------------------------------------------------------

main :: IO ()
main =
  do
    txt <- getContents
    calculator (lines txt) []

-- | read-eval-print loop
calculator :: [String] -> Env -> IO ()
calculator [] _ = return ()
calculator (l : ls) env = do
  let (result, env') = execute l env
  putStrLn result
  calculator ls env'

-- | execute a single expression
execute :: String -> Env -> (String, Env)
execute txt env =
  case parse command txt of
    [(Assign var tree, "")] -> let result = eval tree env in (show result, updateEnv var result env)
    [(Expr tree, "")] -> (show (eval tree env), env)
    _ -> ("parse error; try again", env)
