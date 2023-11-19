def longest(s:str) -> int: return max([len(x) for x in s.split()])

def longest(s:str) -> int: return max(map(lambda x: len(x), s.split()))