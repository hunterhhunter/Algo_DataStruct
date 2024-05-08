import sys
sinput = sys.stdin.readline

n, k = map(int, sinput().split())
lst = []

for _ in range(n):
    lst.append(int(sinput()))

start, end = 1, max(lst)//(k//n)
mid = 0
while start <= end: # 이분탐색 시작
    total = 0
    mid = (start + end) // 2

    for i in lst:
        total += i // mid

    if total >= k:
        start = mid + 1 # 이미 start는 mid에서 고려되었기 때문에 +1
    else:
        end = mid - 1 # 이미 end는 mid에서 고려되었기 때문에 -1
print(end)