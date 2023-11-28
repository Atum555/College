# One-liner
def shorten(suffixes:list, base:int): return lambda n: (str(n) if type(n) != str or not n.isdigit() else list(str(v) + " " + s for i, s in enumerate(suffixes[::-1]) if (v := int(n) // (base ** (len(suffixes)-1-i))))[0])
    
# Normal
def shorten(suffixes:list, base:int):
    def convert(n:str):
        if type(n) != str or not n.isdigit(): return str(n)
        for i, s in enumerate(suffixes[::-1]):
            if (v := int(n) // (base ** (len(suffixes)-1-i))): return str(v) + " " + s
    return convert