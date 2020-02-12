a, b = 0, 1
for x in range(1, 101, 1):
    print("The",x,"num is",b, end='\n')
    a, b = b, a + b;
