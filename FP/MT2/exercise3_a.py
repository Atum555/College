def dict_to_tuple(adict:dict): return [(x,z) for x,y in adict.items() for z in y], [x for x,y in adict.items() if y == []]