def palindrome_index(s:str) -> int:
    def isPalindrome(s:str) -> bool:
        for i in range(len(s)//2):
            if not s[i] == s[-(i+1)]: return False
        return True

    if isPalindrome(s): return -1
    for i in range(len(s)):
        if isPalindrome(s[:i]+s[i+1:]): return i
    return -1