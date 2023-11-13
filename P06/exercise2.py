def mastermind(guesses:list, codes:list) -> tuple:
    guessesU = [False for _ in guesses]
    codesU = [False for _ in codes]
    result = [0,0]
    for i in range(len(guesses)): 
        if guesses[i] == codes[i]: 
            result[0] += 1
            guessesU[i] = codesU[i] = True
    for i in range(len(guesses)):
        for j in range(len(codes)):
            if not guessesU[i] and not codesU[j]:
                if guesses[i] == codes[j]:
                    result[1] += 1
                    guessesU[i] = codesU[j] = True
    return tuple(result)