def sparse_dot_product(dict1:dict,dict2:dict) -> int:
    result = 0
    for x in dict1:
        if dict2.get(x): result += dict1[x]*dict2[x]
    return result