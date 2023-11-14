def check_friendly(n1:int, n2:int):
    if n1 == n2: return f"identical numbers: {n1}"
    n1_sum = 0
    for x in range(1,n1): 
        if n1 % x == 0: n1_sum += x
    if n1_sum != n2: return f"sum of divisors of {n1} is not {n2}"
    n2_sum = 0
    for x in range(1,n2): 
        if n2 % x == 0: n2_sum += x
    if n2_sum != n1: return f"sum of divisors of {n2} is not {n1}"
    return f"{n1} and {n2} are friendly"