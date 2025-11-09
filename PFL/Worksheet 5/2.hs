data CardSuit = Clubs | Spades | Hearts | Diamonds

data CardFace = Two | Three | Four | Five | Six | Seven | Eight | Nine | Ten | Jack | Queen | King | Ace

data Card = Card CardSuit CardFace

allCards :: [Card]
allCards = [Card suit face | suit <- [Clubs, Spades, Hearts, Diamonds], face <- [Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King]]
