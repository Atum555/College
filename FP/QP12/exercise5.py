import random
def cows_bulls(seed:int):
    random.seed(seed)
    def inner(guess:int):
        correct = random.randint(0,9999)
        correct = [x for x in str(correct)]
        guess = [x for x in str(guess)]
        cows = 0
        bulls = 0
        for i, x in enumerate(correct):
            if guess[i] == x:
                cows += 1
                guess[i] = "A"
                correct[i] = "B"
        for i,x in enumerate(guess):
            for j, y in enumerate(correct):
                if x == y:
                    bulls+= 1
                    guess[i] = "A"
                    correct[i] = "B"

        return (cows, bulls)
    return inner

print(cows_bulls(1234)(2240))
print(cows_bulls(510)(3834))
print(cows_bulls(62678)(9887))