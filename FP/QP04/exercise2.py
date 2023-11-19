# METODO 1
def adigits2(a,b,c):
    arr = [a,b,c]
    arr.sort(reverse=True)
    return arr.pop()*100 + arr.pop()*10 + arr.pop()


# METODO 2
def number(x,y,z):
    return x*100 + y*10 + z

def adigits(a,b,c):
     return min(
        number(a,b,c),
        number(a,c,b),
        number(b,a,c),
        number(b,c,a),
        number(c,a,b),
        number(c,b,a)
    )

