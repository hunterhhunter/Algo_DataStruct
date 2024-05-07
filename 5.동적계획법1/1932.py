import sys
sinput = sys.stdin.readline

n = int(sinput())

lst = []

for _ in range(n):
    lst.append(list(map(int, sinput().split())))

for i in range(n-1, 0, -1):
    for j in range(len(lst[i-1])):
        lst[i-1][j] += max(lst[i][j], lst[i][j+1])

# 아래부터 올라가는 형식

print(lst[0][0])