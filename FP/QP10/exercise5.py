# One-liner
def transitive_closure(r:set): return r if not (newR := {(x[0],y[1]) for x in r for y in r if x[1] == y[0]}) - r else (r | transitive_closure(r | newR))

# Normal
def transitive_closure(r:set):
    comp = lambda r: {(x[0],y[1]) for x in r for y in r if x[1] == y[0]}
    def rec(r): 
        newr = comp(r)
        if not newr - r: return r
        return r | rec(r | newr)
    return rec(r)