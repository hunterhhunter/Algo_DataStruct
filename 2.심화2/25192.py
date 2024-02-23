import sys
input = sys.stdin.readline
num = int(input())
names = dict()
res = 0

for _ in range(num):
    name = input()
    if name == "ENTER\n":
        names = {}
    else:
        if name in names:
            names[name] += 1
        else:
            names[name] = 1

        if names[name] == 1:
            res += 1
        else:
            pass
print(res)