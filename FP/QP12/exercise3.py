from cards import *

BLACK = SUITS[0::3]
NUMBER_CARD = RANKS[:9]
LETTER_CARD = RANKS[9:]

def card_value(card: Card):
    multiplier = 2 if card[0] in BLACK else 1
    value = int(card[1]) if card[1] in NUMBER_CARD else 10 if card[1] in LETTER_CARD[:-1] else 11
    return value * multiplier

def play(seed_value:int):
    random.seed(seed_value)
    deck = create_deck(shuffle=True)
    names = "P1 P2 P3 P4".split()
    hands = {n: h for n, h in zip(names, deal_hands(deck))}
    start_player = choose(names)
    turn_order = player_order(names, start=start_player)

    # Randomly play cards from each player's hand until empty
    points = {n:0 for n in names}
    while hands[start_player]:
        turn_cards = {}
        for name in turn_order:
            card = choose(hands[name])
            hands[name].remove(card)
            turn_cards[name] = card
        turn_points = {}
        for name in turn_cards: 
            turn_points[name] = card_value(turn_cards[name])
        turn_score = sorted(turn_points.items(), key=lambda x: x[1], reverse=True)
        for i in range(len(turn_score)):
            if i == 0: points[turn_score[i][0]] += 1
            elif turn_score[i][1] == turn_score[i-1][1]:
                points[turn_score[i][0]] += 1
            else:
                break

    game_score = sorted(points.items(), key=lambda x: x[1], reverse=True)
    result = ""
    for i in range(len(game_score)):
        if i == 0: result += game_score[i][0]
        elif game_score[i][1] == game_score[i-1][1]:
            result += " " + game_score[i][0]
        else:
            break
    return result