def generate(word:str):
    results = []

    if word[-1] == "I": results.append(word+"U")
    for i, l in enumerate(word):
        if l == "M":
            results.append(word[:i+1] + 2* word[i+1:])
    
    for i,l in enumerate(word):
        if l == "I":
            try:
                if word[i+1] == "I" and word[i+2] == "I":
                    results.append(word[:i] + "U" + word[i+3:])
            except:
                pass
    
    for i,l in enumerate(word):
        if l == "U":
            try:
                if word[i+1] == "U":
                    results.append(word[:i] + word[i+2:])
            except:
                pass

    return sorted({k:0 for k in results}.keys())

