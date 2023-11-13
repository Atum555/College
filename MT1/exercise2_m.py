t1 = int(input())
t2 = int(input())
t3 = int(input())
t4 = int(input())

if t3 < 40 and t4 < 40: print("RFF"); exit()

grade = (max(min(t1,t2), max(t3,t4)) + max(t1,t2))/2
print(round(grade)) 