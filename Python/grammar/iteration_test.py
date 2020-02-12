list = [1, 2, 3, 4, 5, 6, 7, 8, 9]

point = iter(list)
point2 = iter(list)

for x in point:
    print(x, end=" ")
else:
    pass


while True:
    try:
        print(next(point2))
    except:
        break
