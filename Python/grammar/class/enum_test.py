from enum import Enum, unique

lista = [1, 2, 3, 4]

for i, v in enumerate(lista):
    print(i, v)

print()

Day = Enum('days', ('one', 'two', 'three', 'four'))

vara = Day.one
print(vara.value)
print(vara)

print()


@unique
class Weekday(Enum):
    Sun = 0  # Sun的value被设定为0
    Mon = 1
    Tue = 2
    Wed = 3
    Thu = 4
    Fri = 5
    Sat = 6


print(Weekday.Wed)
