def search_map(map:tuple, map_rectangle:tuple, search_rectangle:tuple):
    s = (search_rectangle[0], search_rectangle[1], search_rectangle[0] + search_rectangle[2], search_rectangle[1] + search_rectangle[3])
    p = {
        0: (map_rectangle[0], map_rectangle[1], (map_rectangle[0] + map_rectangle[2])//2, (map_rectangle[1] + map_rectangle[3])//2),
        1: ((map_rectangle[0] + map_rectangle[2])//2, map_rectangle[1], map_rectangle[2], (map_rectangle[1] + map_rectangle[3])//2),
        2: ((map_rectangle[0] + map_rectangle[2])//2, (map_rectangle[1] + map_rectangle[3])//2, map_rectangle[2], map_rectangle[3]),
        3: (map_rectangle[0], (map_rectangle[1] + map_rectangle[3])//2, (map_rectangle[0] + map_rectangle[2])//2, map_rectangle[3])
    }
    result = set()
    for i, quad in enumerate(map):
        if quad is None: continue
        qP = p[i]

        # Check intersection with search
        if not (qP[0] < s[2] and qP[1] < s[3] and qP[2] > s[0] and qP[3] > s[1]): continue
        
        if type(quad) == tuple:
            result |= search_map(quad, qP, search_rectangle)
        else:
            result.add(quad)
    return result