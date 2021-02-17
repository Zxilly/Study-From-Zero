from functools import partial

int8 = partial(int, base=8)

print(int8('10'))

print(int8("4"))
