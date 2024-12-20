dimensions = int(input())

vector1 = []
vector2 = []

for i in range(dimensions):
    vector1.append(float(input()))

for i in range(dimensions):
    vector2.append(float(input()))

scalar_product = 0

for i in range(dimensions):
    scalar_product += vector1[i] * vector2[i]
    
print("Scalar product =", scalar_product)
