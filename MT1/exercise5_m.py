def validate_cc(n:int):
    narr = list(reversed([int(x) for x in str(n)]))
    for i in range(len(narr)): narr[i] = sum([int(x) for x in str(narr[i] * (1 + i%2))])
    return f"Card number {n} {'valid' * (sum(narr)%10==0)}{'invalid' *(abs((sum(narr)%10==0)-1))}{(abs((sum(narr)%10==0)-1)) * f' (checksum {sum(narr)%10})'}"