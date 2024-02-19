import sys

sinput = sys.stdin.readline


a = int(input())

for i in range(a):
    gal = list()
    gals = list(input())
    for ga in gals:
        gal.append(ga)
        if len(gal) != 1:
            if gal[len(gal)-2]+gal[len(gal)-1] == "()":
                gal.pop()
                gal.pop()

    if gal:
        print("NO")
    else:
        print("YES")
        