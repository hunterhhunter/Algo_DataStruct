n = int(input())
lst = list(map(int, input().split()))

# 제거하지 않은 경우
# 음수 나올 시 우 연속수열의 합이 음수보다 크면 음수 포용
dp1 = [lst[i] for i in range(1, n)]
