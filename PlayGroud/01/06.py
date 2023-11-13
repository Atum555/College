import math
angle = int(input())*math.pi/180  # convert to radians

range = ((18**2) * math.sin(2*angle))/10
print(round(range))