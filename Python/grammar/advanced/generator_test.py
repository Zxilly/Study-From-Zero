a = (x * x for x in range(20))

for i in a:
    print(i)


def fib(maxnum):
    n, a, b = 0, 0, 1
    while n < maxnum:
        yield b
        a, b = b, a + b
        n = n + 1
    return 'done'


for one in fib(20):
    print(one)
