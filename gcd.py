def divisors(n:int) -> set[int]: return {x for x in range(1,n+1) if n % x == 0}

a = 14
b = 21

div = {a: divisors(a),
       b: divisors(b)}

linear_combinations = {x*a+y*b for x in range(1,5) for y in range(3)}
for comb in linear_combinations:
    #print(f"{comb}: {divisors(comb)}")
    print(divisors(comb) & divisors(a) & divisors(b) == divisors(a) & divisors(b))