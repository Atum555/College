# One-liner
def square_odds(values:str): return ",".join(map(str, map(lambda x: int(x)**2, filter(lambda x: int(x) % 2 == 1, values.split(",")))))

# Normal
def square_odds(values:str):
    valuesList = values.split(",")          # Split values
    valuesList = map(int, valuesList)       # Convert to int

    isOdd = lambda x: x % 2 == 1            # Function to check if number is odd
    valuesList = filter(isOdd, valuesList)  # Select only odd numbers

    square = lambda x: x**2                 # Function that returns the square of a given number
    valuesList = map(square, valuesList)    # Compute squares

    valuesList = map(str, valuesList)       # Convert int to string
    result = ",".join(valuesList)           # Join string seperated by a comma
    return result