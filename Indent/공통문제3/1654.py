import sys
sinput = sys.stdin.readline

n, k = map(int, sinput().split())
lst = []

for _ in range(n):
    lst.append(int(sinput()))

start, end = 1, max(lst)//(k//n) 
# 가장 큰 랜선은 적어도 k//n개로는 나뉘어야 함
mid = 0
while start <= end: # 이분탐색 시작
    total = 0
    mid = (start + end) // 2 # 탐색 범위의 중앙값

    for i in lst:
        total += i // mid # 중앙값으로 나눈 몫
        
    if total >= k:
        start = mid + 1 # 이미 start는 mid에서 고려되었기 때문에 +1
    else:
        end = mid - 1 # 이미 end는 mid에서 고려되었기 때문에 -1
print(end)