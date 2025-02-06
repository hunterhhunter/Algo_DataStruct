n = int(input())

lst = list(map(int, input().split()))
dp = [lst[i] for i in range(n)]
dp[0] = lst[0]

# dp[i]를 max에 넣지 않으니 자꾸 마음대로 초기화가 되는 문제. 해결
# dp배열 선언시 0으로 선언하니 앞의 값들보다 작은 값은 초기화가 안되는 문제
# dp배열을 lst카피로 해결

for i in range(1, n):
    tmp = lst[i]
    sums = 0
    for j in range(i):
        if tmp > lst[j]:
            dp[i] = max(dp[i], dp[j] + tmp)
print(max(dp))