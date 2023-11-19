import math
def time_until_lost_connection(direction_A, direction_B):
    return round(((35 / 2) / (abs(math.sin(math.radians(abs(direction_A - direction_B))/2))) / 5)*60,3)