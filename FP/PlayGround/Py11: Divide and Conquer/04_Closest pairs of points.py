import math
def closest_pair(points:list, ordered:bool = False):
    if not ordered:
        points.sort(key=lambda x: x[0])
    
    if len(points) == 2:
        return math.sqrt((points[0][0] - points[1][0])**2 + (points[0][1] - points[1][1])**2)

    L = points[:len(points)//2]
    R = points[len(points)//2:]
    if len(R) > 1: dR = closest_pair(R, True)
    if len(L) > 1: dL = closest_pair(L, True)

    dLR = min(dR, dL) if len(R) > 1 and len(L) > 1 else dR if len(R) > 1 else dL
    dM = None
    for x in L:
        for y in R:
            if abs(x[0] - y[0]) < dLR:
                if not dM: 
                    dM = math.sqrt((x[0] - y[0])**2 + (x[1] - y[1])**2)
                else:
                    t = math.sqrt((x[0] - y[0])**2 + (x[1] - y[1])**2)
                    dM = t if t < dM else dM
    return round(min(dM, dLR) if dM is not None else dLR)