def nested_exceptions(tree:tuple):
    r = []
    for x in tree:
        if callable(x):
            try: 
                x()
                r.append(False)
            except:
                r.append(True)
        else:
            r.append(nested_exceptions(x))
    return tuple(r)