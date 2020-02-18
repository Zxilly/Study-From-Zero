f = {1: 'Google', 2: 'Microsoft', 3: 'Amazon', 'expensive': 'Apple'}

'''
for x in range(1,11):
    print('{0:5d}{1:5d}{2:5d}'.format(x,x*x,x*x*x))
'''

print('1:{0[1]}'.format(f))

print('{expensive}'.format(**f))
