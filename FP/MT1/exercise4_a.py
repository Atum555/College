def sum_odd_even(n:int) -> str:
    sumE = 0
    sumO = 0
    while n>0:
        d = n%10
        if d%2: sumO += d
        else: sumE += d
        n //= 10
    if sumE == sumO: return f"identical sum = {sumO}"
    return f"even sum = {sumE}, odd sum = {sumO}"