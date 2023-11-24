def total_distance(dist:dict, cities:list) -> int:
    if len(cities) < 2: return 0
    distance = 0
    for i in range(len(cities)-1):
        if   (cities[i], cities[i+1]) in dist: distance += dist[(cities[i], cities[i+1])]
        elif (cities[i+1], cities[i]) in dist: distance += dist[(cities[i+1], cities[i])]
        else: return -1
    return distance