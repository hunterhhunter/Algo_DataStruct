import sys
sinput = sys.stdin.readline

n = int(sinput())
lst = []
table = [1 for _ in range(n)]
for _ in range(n):
    lst.append(list(map(int, sinput().split())))

lst.sort()

for i in range(1, n):
    for j in range(i):
        if lst[j][1] < lst[i][1]:
            table[i] = max(table[i], table[j]+1)

print(n-max(table)) 