def isomorphic(astr1: str, astr2: str) -> str:
    def getAllPossitions(s:str, l:str) -> list:
        result = []
        for i, x in enumerate(s):
            if x == l: result.append(i)
        return result
    
    result = 0
    for i, letter in enumerate(astr1):
        if getAllPossitions(astr1, letter) != getAllPossitions(astr2, astr2[i]): 
            result = 1; break
    
    return f"'{astr1}' and '{astr2}' are {'not ' * result}isomorphic"