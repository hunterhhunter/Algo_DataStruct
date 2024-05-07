import sys
sinput = sys.stdin.readline

n, k = map(int, sinput().split())
lst = []

for _ in range(n):
    lst.append(int(sinput()))

start, end = 1, max(lst)
mid = 0
while start <= end:
    total = 0
    mid = (start + end) // 2

    for i in lst:
        total += i // mid

    if total >= k:
        start = mid + 1
    else:
        end = mid - 1
print(end)
