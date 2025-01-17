n = int(input())
lst = list(map(int, input().split()))
lst.insert(0, 0)
dp = [0 for _ in range(n+1)]


# 1차원 배열로 선언한 후 i까지 선언해 
# lst[j]+dp[i-j]와 현재 dp[i]를 비교하면 된다.
# 이 때 i-j만 떠올리면 되는데 왜 그렇게 복잡하게 풀었니?
for i in range(1, n+1):
    for j in range(1, i+1):
        dp[i] = max(dp[i], lst[j]+dp[i-j])

print(dp[n])