n, k = map(int, input().split())

lis = list(map(int, input().split()))
ls = sum(lis[:k])
result = ls

for i in range(k, n):
    ls += lis[i] - lis[i-k]
    result = max(result, ls)

print(result)