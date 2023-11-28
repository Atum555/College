"""
Code By: Cláudio Meireles

Code on GitHub: https://github.com/Atum555/College/blob/main/FP/Ch04/gauss.py

Minimum version tested: 3.10.12
(Type hints used)
"""


from typing import TypeAlias

Matrix: TypeAlias = list[list[int|float]]


def gauss(matrix:Matrix):
    """
    Performs Gaussian elimination on a matrix.

    Args:
    - matrix (list): The matrix to perform Gaussian elimination on.
    """

    def check_matrix(matrix:Matrix) -> bool:
        """
        Checks if a matrix is valid.

        Args:
        - matrix (Matrix): The matrix to check.

        Returns:
        - bool: True if the matrix is valid, False otherwise.
        """
        lines = len(matrix)
        cols = len(matrix[0])
        if cols != lines +1: return False
        for line in matrix:
            if len(line) != cols: return False
        return True
    
    def switch_rows(matrix:Matrix, a:int, b:int) -> None:
        """
        Switches two rows in the matrix.

        Args:
        - matrix (Matrix): The matrix to modify.
        - a (int): The index of the first row to switch.
        - b (int): The index of the second row to switch.
        """
        temp = matrix[a]
        matrix[b] = matrix[a]
        matrix[b] = temp

    def add_rows(matrix:Matrix, from_a:int, to_b:int, k:int|float) -> None:
        """
        Adds a multiple of one row to another row in the matrix.

        Args:
        - matrix (Matrix): The matrix to modify.
        - from_a (int): The index of the row where to grab values from.
        - to_b (int): The index of the row to modify.
        - k (int|float): The multiplier.
        """
        for col in range(len(matrix[0])): matrix[to_b][col] += matrix[from_a][col] * k

   
    if not check_matrix(matrix): raise ValueError("Invalid Matrix.")
    
    # Transformar a submatrix dos coeficientes numa triangular superior,
    # Com as entradas da diagonal principal igual a 1.
    for col in range(len(matrix[0])-1):
        # Make the first entry non-zero
        index = col
        while matrix[col][col] == 0 and index < len(matrix):
            if matrix[index][col] != 0: switch_rows(matrix, index, col)
            index += 1
        #multiply_row(matrix, col, 1/matrix[col][col]) # Turn the first entry into a 1 
            
        # Make all values under the first position 0's
        for line in range(len(matrix)):
            if line <= col: continue     # Ignore lines before current submatrix and the first
            if matrix[line][col] != 0: add_rows(matrix, col, line, -matrix[line][col]/matrix[col][col])


    result = []
    try:
        for i in range(-1, -len(matrix)-1, -1):
            subTotal = matrix[i][-1]                    # Adicionar termo independente
            for j in range(-2, i-1, -1): 
                subTotal -= result[j-i] * matrix[i][j]  # Subtrair variaveis * coeficientes
            
            subTotal /= matrix[i][i-1]                  # Dividir por coeficiente

            if subTotal == -0: subTotal = 0
            result.insert(0, round(subTotal,7))
    except: raise ValueError
    
    return result