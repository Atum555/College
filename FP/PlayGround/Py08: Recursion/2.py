def next_prime(number):
    if number <= 1: return 2
    list = [0]
    x = number
    while list[-1] <= number:
        counter = 0
        for i in range(1, x//2 + 1):
            if x % i == 0: 
                counter += 1
                if counter > 2: break
        if counter == 1: list.append(x)
        x += 1
    return list[-1]
import random

print(next_prime(45000000))