{-
  A simple purely functional parsing library
  Based on Chapter 8 of "Programming in Haskell" by Graham Hutton
  Pedro Vasconcelos, 2025
-}
module Parsing
  ( Parser,
    parse,
    (<|>),
    failure,
    satisfy,
    getc,
    char,
    many,
    many1,
  )
where

-- | the type of parsers:
--  "A parser for things
--   is a function from strings
--   to lists of pairs
--   of things and strings"
newtype Parser a = P (String -> [(a, String)])

-- | apply a parser
parse :: Parser a -> String -> [(a, String)]
parse (P f) s = f s

-- | Monad instance;
-- this allows us to use do-notation for combining parsers
instance Monad Parser where
  -- return :: a -> Parser a
  -- `return' must be defined as `pure' in GHC>=9.6.x
  return = pure

  -- (>>=) :: Parser a -> (a -> Parser b) -> Parser b
  p >>= f =
    P
      ( \s -> case parse p s of
          [] -> []
          [(v, s')] -> parse (f v) s'
      )

-- | Monad requires instances of Functor and Applicative
-- these are just dummy instances to ensure GHC does not complain
instance Functor Parser where
  fmap = error "Functor instance is incomplete"

instance Applicative Parser where
  pure x = P (\s -> [(x, s)])
  (<*>) = error "Applicative instance is incomplete"

-- | alternative between two parsers
-- apply the first parser; if it succeeds return the result;
-- otherwise try the second parser
infixl 5 <|>

(<|>) :: Parser a -> Parser a -> Parser a
p <|> q =
  P
    ( \s -> case parse p s of
        [] -> parse q s
        [(v, s')] -> [(v, s')]
    )

-- | a parser that always fails
failure :: Parser a
failure = P (\s -> [])

-- | a parser that return the next character (if any)
getc :: Parser Char
getc =
  P
    ( \s -> case s of
        (x : xs) -> [(x, xs)]
        [] -> []
    )

-- | parse a character that satisfies a predicate (boolean function)
satisfy :: (Char -> Bool) -> Parser Char
satisfy f = do
  x <- getc
  if f x then return x else failure

-- | parse a given character
char :: Char -> Parser Char
char c = satisfy (== c)

-- | apply a parser zero or more times;
-- returns the list of results
many :: Parser a -> Parser [a]
many p = many1 p <|> return []

-- | apply a parser one or more times;
-- return the list of results
many1 :: Parser a -> Parser [a]
many1 p = do
  v <- p
  vs <- many p
  return (v : vs)
