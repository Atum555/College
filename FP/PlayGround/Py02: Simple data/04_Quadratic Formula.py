import math
a = float(input())
b = float(input())
c = float(input())
print("The solutions are", round((-b+math.sqrt(b**2-4*a*c))/(2*a),2), "and" , round((-b-math.sqrt(b**2-4*a*c))/(2*a),2))