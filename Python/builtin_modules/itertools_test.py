import itertools

for i in itertools.count(0, 20):
    print(i)
    if i >= 200:
        break

for key, group in itertools.groupby('AaaBABbcCAAa', lambda c: c.upper()):
    print(key, list(group))
