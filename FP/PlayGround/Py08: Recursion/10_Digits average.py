def avg(n:int) -> int: return (n % 10 + (n//10) %10)//2 + (n % 10 + (n//10) %10) %2 + 10* avg(n//10) if n >= 10 else 0
def digits_average(n:int) -> int:
    return n if n < 10 else digits_average(avg(n))