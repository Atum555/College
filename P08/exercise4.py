def permutations(text:str)-> list:
    if len(text) <2 : return [text]
    result = []
    for i,l in enumerate(text):
        for x in permutations(text[:i]+text[i+1:]):
            result.append(l+x)
    return result