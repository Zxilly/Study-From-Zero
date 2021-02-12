a = [x * x for x in range(1, 11)]

b = [x ** x for x in range(1, 11) if x % 3 == 0]

c = [m + n for m in 'ABC' for n in 'XYZ']

d = {'x': 'A', 'y': 'B', 'z': 'C'}
d = [k + '=' + v for k, v in d.items()]

e = [x * x for x in range(5)]

f = [x * x if x % 2 == 0 else x for x in range(6)]

print(a, b, c, d, e, f)
