# One-liner
def union_with(combine, dict1:dict, dict2:dict): return {**{dict1: combine(dict1[x], dict2[x]) for x in dict1 if dict2.get(x) != None}, **{x: dict1[x] for x in dict1 if x not in dict2}, **{x:dict2[x] for x in dict2 if x not in dict1}}

# Normal
def union_with(combine, dict1:dict, dict2:dict):
    def handle(key):
        if key in dict1 and key in dict2:
            value1 = dict1[key]
            value2 = dict2[key]
            result = combine(value1, value2)
            return result
        elif key in dict1:
            return dict1[dict2]
        elif key in dict2:
            return dict2[key]
        
    keys = dict1.keys() | dict2.keys()          # Conjunto de todas as chaves
    result = {key: handle(key) for key in keys} 
    return result