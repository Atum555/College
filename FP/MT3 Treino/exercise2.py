def shopping(alist:dict, stock:dict):
    spent = 0
    missing = alist

    for item in alist:
        if item not in stock.keys(): continue
        wanted = alist[item]
        available = stock[item][0]
        if available >= wanted:
            spent += wanted * stock[item][1]
            missing[item] -= wanted
        else:
            spent += stock[item][0] * stock[item][1]
            missing[item] -= stock[item][0]

    missing = {k:v for k,v in missing.items() if v != 0}
    return (spent, missing)