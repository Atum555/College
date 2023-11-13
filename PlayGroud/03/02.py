LE = int(input())
RE = int(input())
PE = int(input())
TE = int(input())

grade = (LE + RE + 13* PE + 5* TE) / 100
grade = int(grade//1 + (grade%1>=0.5))

IR = not ((0<=LE<=100) * (0<=RE<=100) * (0<=PE<=100) * (0<=TE<=100))
RFF = (PE<40) | (TE<40)

print(str(grade)*abs(IR-1)*abs(RFF-1) + "Input error" * IR + "RFF" * RFF * abs(IR-1))