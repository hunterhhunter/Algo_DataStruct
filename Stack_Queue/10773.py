import sys

sinput = sys.stdin.readline

num = int(sinput())
su = list()

for i in range(num):
    a = int(sinput())
    if a == 0:
        su.pop()
    else:
        su.append(a)

print(sum(su))