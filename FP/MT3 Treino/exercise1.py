def days_until_christmas(date):
    d = date[0]
    m = date[1]

    days_of_month = {
    1: 31,
    2: 28,
    3: 31,
    4: 30,
    5: 31,
    6: 30,
    7: 31,
    8: 31,
    9: 30,
    10: 31,
    11: 30,
    12: 31
    }


    if m == 12 and d > 25:
        return 31-d + 359
    if m == 12:
        return 25-d
    
    days = days_of_month[m]-d
    m+=1
    while m != 12:
        days += days_of_month[m]
        m += 1
    days += 25
    return days