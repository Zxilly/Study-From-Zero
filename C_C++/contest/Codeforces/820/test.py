for i in range(25):
    print('?',1,i+2,flush=1)
    d=int(input())
    print('?',i+2,1,flush=1)
    d2=int(input())
    if d==-1:
        print('!',i+1,flush=1)
        break
    elif d!=d2:
        print('!',d+d2)
        break