def last_man_standing(alist:list, step:int, position:int = -1):
    if len(alist) == 1: return alist[0]
    p = (position+step) % len(alist)
    alist.pop(p)
    return last_man_standing(alist, step, position=p-1)
