rows = int(input("Number of rows ="))
cols = int(input("Number of columns ="))
matrix = [[float(input(f"a[{row}][{col}]=")) for col in range(cols)] for row in range(rows)]

for row in matrix: print(row)

transpose_matrix = [[matrix[row][col] for row in range(rows)] for col in range(cols)]

print("Matrix transpose:")

for row in transpose_matrix: print(row)
