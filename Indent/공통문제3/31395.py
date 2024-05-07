n = int(input())
res = 1
tmp = 1
lst = list(map(int, input().split()))

for i in range(1, n):
    if lst[i] > lst[i-1]:
        tmp += 1
        res += tmp
    else:
        res += 1
        tmp = 1
print(res)