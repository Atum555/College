def cycle_length_cheating(number: int, digits: int) -> int:
    def next_middle_square(number, digits):
        """Compute the next pseudo-random using the 
            middle square algorithm and the given number of digits."""
        k = digits // 2         # half of the number of digits
        square = number*number  # compute the square
        middle = (square // (10**k)) % (10**digits)   # extract middle part
        return middle

    numbers = []
    while True:
        number = next_middle_square(number, digits)
        if number in numbers: return len(numbers) - numbers.index(number)
        numbers.append(number)


def cycle_length(number: int, digits: int) -> int:
    def next_middle_square(number, digits):
        """Compute the next pseudo-random using the 
            middle square algorithm and the given number of digits."""
        k = digits // 2         # half of the number of digits
        square = number*number  # compute the square
        middle = (square // (10**k)) % (10**digits)   # extract middle part
        return middle

    numbers = set()
    while True:
        number = next_middle_square(number, digits)
        if number in numbers:
            n = number
            counter = 0
            while True:
                number = next_middle_square(number, digits)
                counter += 1
                if n == number: return counter
        numbers.add(number)