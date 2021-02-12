from collections.abc import Iterable

print(isinstance([], Iterable))

print(isinstance(str, Iterable))
print(isinstance('abc', Iterable))
print(type(str))
print(type('abc'))

print(isinstance((x for x in range(10)), Iterable))


def countTo(num):
    count = 1
    while count <= num:
        yield count
        count += 1
    return count


print(isinstance(countTo(20), Iterable))
