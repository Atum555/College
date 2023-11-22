<<<<<<< HEAD
def last_man_standing(list:list, step:int) -> str:
=======
def last_man_standing(list:list, step:int):
>>>>>>> 3cf3982dc10154c5adb8abe756642859f9f6a9e7
    to_remove = -1
    while len(list) > 1: 
        to_remove = (to_remove + step) % len(list)
        list.pop( to_remove )
        to_remove -= 1
    return list[0]