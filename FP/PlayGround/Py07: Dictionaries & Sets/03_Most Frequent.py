def most_frequent(alist:list):
    dic = {}
    for element in alist:
        if dic.get(element): dic[element] += 1
        else: dic[element] = 1
    biggest = (0,0)
    for element in dic:
        if dic[element] > biggest[1]: biggest = (element, dic[element])
        if dic[element] == biggest[1] and element > biggest[0]: biggest = (element, dic[element])
    return biggest[0]