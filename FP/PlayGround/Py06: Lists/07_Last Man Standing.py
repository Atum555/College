def last_man_standing(list:list, step:int):
    to_remove = -1
    while len(list) > 1: 
        to_remove = (to_remove + step) % len(list)
        list.pop( to_remove )
        to_remove -= 1
    return list[0]