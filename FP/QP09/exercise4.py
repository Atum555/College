def dec2int(alist:list):
    from functools import reduce
    return reduce(lambda x,y: x*10+y, alist)