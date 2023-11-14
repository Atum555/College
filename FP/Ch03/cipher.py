def cipher(message:str, key:str, decode:bool=False):
    """
    This function encodes or decodes a message using a key.
    The key must be a string containing only alphabetical characters.
    The message can contain any characters.
    The function returns the encoded/decoded message.
    
    Parameters:
    message (str): The message to be encoded/decoded.
    key (str): The key to be used for encoding/decoding.
    decode (bool): If True, the function will decode the message using the key. Default is False.
    
    Returns:
    str: The encoded/decoded message.
    """
    # Check if key is valid
    for x in key:
        if not x.isalpha(): return F"INVALID KEY, CHAR: {x}"
    
    # Extend KEY to match messega length
    key = key*(len(message)//len(key)) + key[:len(message)%len(key)]

    # Encode/Decode
    encoded = ""
    message = message.upper()
    key = key.upper()
    nonAlphaChr = 0
    for index, letter in enumerate(message):
        if letter.isalpha():
            shift = ord(key[index-nonAlphaChr]) - ord("A")
            chrCode = ord(letter) + shift * (-1) ** int(decode)
            chrCode = (chrCode - 26) if chrCode > ord("Z") else (chrCode + 26) if chrCode < ord("A") else chrCode
            encoded += chr(chrCode)
        else: encoded += letter; nonAlphaChr += 1
    return encoded


def main():
    message = input("Message to encode/decode: ")
    key = input("Key: ")
    print(cipher(message, key))


if __name__ == "__main__":
    main()