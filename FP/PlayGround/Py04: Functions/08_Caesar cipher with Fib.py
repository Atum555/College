def fib(n:int):
    """
    Returns the nth number in the Fibonacci sequence.

    Parameters:
    n (int): The index of the number to be returned.

    Returns:
    int: The nth number in the Fibonacci sequence.
    """
    return int(((1+5**0.5)**n-(1-5**0.5)**n)/((2**n)*(5**0.5)))
        

def caesar(message:str):
    """
    Encrypts a message using the Caesar cipher with a key generated from the Fibonacci sequence.

    Args:
        message (str): The message to be encrypted.

    Returns:
        str: The encrypted message.
    """
    new_message = ""
    for i, x in enumerate(message):
        if x.isalpha(): new_message += chr((ord(x) - ord("A") - fib(i)) % 26 + ord("A"))
        else: new_message += x
    return new_message