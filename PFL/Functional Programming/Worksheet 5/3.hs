import Data.List (sortBy)

data CardSuit = Clubs | Spades | Hearts | Diamonds
  deriving (Eq, Ord, Show)

data CardFace = Two | Three | Four | Five | Six | Seven | Eight | Nine | Ten | Jack | Queen | King | Ace
  deriving (Eq, Ord, Show)

data Card = Card CardSuit CardFace
  deriving (Eq, Ord)

instance Show Card where
  show :: Card -> String
  show (Card suit face) = "(" ++ show face ++ " - " ++ show suit ++ ")"

allCards :: [Card]
allCards = [Card suit face | suit <- [Clubs, Spades, Hearts, Diamonds], face <- [Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King]]

cmp1 :: Card -> Card -> Ordering
cmp1 = compare

-- >>> cmp1 (Card Spades Four) (Card Clubs Nine)
-- >>> cmp1 (Card Spades Four) (Card Spades Two)
-- >>> cmp1 (Card Spades Four) (Card Spades Nine)
-- >>> cmp1 (Card Spades Four) (Card Spades Four)
-- GT
-- GT
-- LT
-- EQ

-- >>> sortBy cmp1 allCards
-- [(Two - Clubs),(Three - Clubs),(Four - Clubs),(Five - Clubs),(Six - Clubs),(Seven - Clubs),(Eight - Clubs),(Nine - Clubs),(Ten - Clubs),(Jack - Clubs),(Queen - Clubs),(King - Clubs),(Ace - Clubs),(Two - Spades),(Three - Spades),(Four - Spades),(Five - Spades),(Six - Spades),(Seven - Spades),(Eight - Spades),(Nine - Spades),(Ten - Spades),(Jack - Spades),(Queen - Spades),(King - Spades),(Ace - Spades),(Two - Hearts),(Three - Hearts),(Four - Hearts),(Five - Hearts),(Six - Hearts),(Seven - Hearts),(Eight - Hearts),(Nine - Hearts),(Ten - Hearts),(Jack - Hearts),(Queen - Hearts),(King - Hearts),(Ace - Hearts),(Two - Diamonds),(Three - Diamonds),(Four - Diamonds),(Five - Diamonds),(Six - Diamonds),(Seven - Diamonds),(Eight - Diamonds),(Nine - Diamonds),(Ten - Diamonds),(Jack - Diamonds),(Queen - Diamonds),(King - Diamonds),(Ace - Diamonds)]

cmp2 :: Card -> Card -> Ordering
cmp2 (Card suit1 face1) (Card suit2 face2) = case compare face1 face2 of
  EQ -> compare suit1 suit2
  other -> other

-- >>> cmp1 (Card Spades Four) (Card Clubs Nine)
-- >>> cmp1 (Card Spades Four) (Card Hearts Four)
-- >>> cmp1 (Card Spades Four) (Card Spades Nine)
-- >>> cmp1 (Card Spades Four) (Card Spades Four)
-- GT
-- LT
-- LT
-- EQ

-- >>> sortBy cmp2 allCards
-- [(Two - Clubs),(Two - Spades),(Two - Hearts),(Two - Diamonds),(Three - Clubs),(Three - Spades),(Three - Hearts),(Three - Diamonds),(Four - Clubs),(Four - Spades),(Four - Hearts),(Four - Diamonds),(Five - Clubs),(Five - Spades),(Five - Hearts),(Five - Diamonds),(Six - Clubs),(Six - Spades),(Six - Hearts),(Six - Diamonds),(Seven - Clubs),(Seven - Spades),(Seven - Hearts),(Seven - Diamonds),(Eight - Clubs),(Eight - Spades),(Eight - Hearts),(Eight - Diamonds),(Nine - Clubs),(Nine - Spades),(Nine - Hearts),(Nine - Diamonds),(Ten - Clubs),(Ten - Spades),(Ten - Hearts),(Ten - Diamonds),(Jack - Clubs),(Jack - Spades),(Jack - Hearts),(Jack - Diamonds),(Queen - Clubs),(Queen - Spades),(Queen - Hearts),(Queen - Diamonds),(King - Clubs),(King - Spades),(King - Hearts),(King - Diamonds),(Ace - Clubs),(Ace - Spades),(Ace - Hearts),(Ace - Diamonds)]
