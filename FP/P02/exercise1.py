import math

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

num = int(input())
powers = [1]
for i in range(1, num):
    powers.append(num**i)

i = 1
while True:
    if i in powers:
        print(f'{bcolors.WARNING}{num} ^ {int(math.log(i,num)+1)} = {num*i}{bcolors.ENDC}')
        if i == powers[-1]: break
    
    print(f"{num} x {i} = {num * i}")

    i += 1
    #if i > 100: break