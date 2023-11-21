def x_union(list1:list, list2:list) -> list: 
    l1 = tuple(map(lambda x: x[0], list1))
    l2 = tuple(map(lambda x: x[0], list2))
    return list(filter(lambda x: x[0] not in l2, list1)) + list(filter(lambda x: x[0] not in l1, list2))