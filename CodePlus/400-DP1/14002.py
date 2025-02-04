n = int(input())

lst = list(map(int, input().split()))
dp = [1 for _ in range(n)]


for i in range(n):
    tmp = lst[i]
    for j in range(i):
        if tmp > lst[j]:
            dp[i] = max(dp[j]+1, dp[i])

res = [0 for _ in range(max(dp))]

# max(dp)값에서 뒤로 가며 증가 수열을 찾으면 그게 가장 긴 부분수열임이 자명

for i in range(max(dp), 0, -1):
    if i == max(dp):
        res[i-1] = lst[dp.index(i)]
        continue
    for j in range(n):
        if dp[j] == i and lst[j] < res[i]:
            res[i-1] = lst[j]
            break

print(max(dp))
print(*res)