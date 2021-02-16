def is_palindrome(n):
    return str(n)[::] == str(n)[::-1]


def is_palindrome2(n):
    print(str(n)[0:-1:1])
    print(str(n)[-1:0:-1])
    return str(n)[0:-1:1] == str(n)[-1:0:-1]


print(is_palindrome2(23456))
