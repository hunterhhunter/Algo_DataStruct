import sys
sinput = sys.stdin.readline

n = int(sinput())
lst = []


for _ in range(n):
    lst.append(list(map(int, sinput().split())))

for i in range(1, n):
    lst[i][0] += min(lst[i-1][1], lst[i-1][2])
    lst[i][1] += min(lst[i-1][0], lst[i-1][2])
    lst[i][2] += min(lst[i-1][0], lst[i-1][1])

print(min(lst[-1]))