def mastermind(g1,g2,g3,c1,c2,c3):
    points = 0
    c1u = c2u = c3u = g1u = g2u = g3u = False # Wheter the color has been used
    
    if c1 == g1: points += 3; c1u = g1u = True
    if c2 == g2: points += 3; c2u = g2u = True
    if c3 == g3: points += 3; c3u = g3u = True
    if c1 == g2 and not g2u and not c1u: points += 1; g2u = c1u = True
    if c1 == g3 and not g3u and not c1u: points += 1; g3u = c1u = True
    if c2 == g1 and not g1u and not c2u: points += 1; g1u = c2u = True
    if c2 == g3 and not g3u and not c2u: points += 1; g3u = c2u = True
    if c3 == g1 and not g1u and not c3u: points += 1; g1u = c3u = True
    if c3 == g2 and not g2u and not c3u: points += 1; g2u = c3u = True
    return points

mastermind(
    "b", "b", "y",
    "y", "y", "b"
    )