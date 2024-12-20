rows = int(input())
cols = int(input())
matrix = [[float(input()) for col in range(cols)] for row in range(rows)]

for row in matrix: row.append(sum(row))

matrix.append([0 for _ in range(len(matrix[0]))])

for col_number in range(cols + 1): matrix[rows][col_number] = sum((matrix[i][col_number] for i in range(cols)))

for row in matrix: print(row)
        
