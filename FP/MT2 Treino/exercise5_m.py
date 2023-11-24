def above(tree:tuple, name:str, people_on_top:list = []):
    if type(tree) == str: return people_on_top if people_on_top and name == tree else None
    if name == tree[0]: return people_on_top if people_on_top else None
    for x in tree[1]:
        result = above(x, name, people_on_top=people_on_top + [tree[0]])
        if result: return result