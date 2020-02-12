import sys

print("Command line parameter is")
for i in sys.argv:
    print(i)

print("\n\nPath is",sys.path),'\n'

print(dir(sys))