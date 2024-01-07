from contextlib import suppress 
def d(a):
    b = None
    with suppress(TypeError, ZeroDivisionError): b = 1/a
    return b
        
def reciprocals(alist:list): return list(filter(None, map(d, alist)))