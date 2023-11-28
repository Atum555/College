# One-liner
def batch_norm(alist:list, batch_size:int):
    while len(alist) > 0: yield [(v := s[len(s)//2] if len(s := sorted(result := [alist.pop(0) for _ in range(batch_size) if len(alist) > 0])) % 2 == 1 else (s[len(s)//2-1] + s[len(s)//2])/2)]*0 + [x - v for x in result]
    

# Normal
def batch_norm(alist:list, batch_size:int):
    while len(alist) > 0:
        result = [alist.pop(0) for _ in range(batch_size) if len(alist) > 0]
        s = sorted(result)
        v = s[len(s)//2] if len(s) % 2 == 1 else (s[len(s)//2-1] + s[len(s)//2])/2
        result = [x - v for x in result]
        yield result