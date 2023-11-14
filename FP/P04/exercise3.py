def sum_until_x(x):
    sum = 0
    for i in range(1, x+1):
        sum += i
    return sum

def var_numbers(number, precision = 2):
    avg = sum_until_x(number) / number
    sum_variance = 0
    for x in range(1, number + 1):
        sum_variance += (x - avg)**2
    return round(sum_variance / number, precision)