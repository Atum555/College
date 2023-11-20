def next_prime(number:int) -> int:
    while True:
        number += 1
        counter = 0
        for i in range(2, number //2 +1):
            if number % i == 0: counter += 1; break
        if counter == 0: return number