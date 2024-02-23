from collections import deque
import sys
sinput = sys.stdin.readline

num = int(sinput())
lis = list(map(int, input().split()))
res = []
idx = 0
im = 0

q = deque(i for i in range(1, num+1))

res.append(q.popleft())

while q:
    if lis[idx] > 0:
        for i in range(lis[idx]-1):
            q.append(q.popleft())
        im = q.popleft()
        res.append(im)
    else:
        for i in range(abs(lis[idx])-1):
            q.appendleft(q.pop())
        im = q.pop()
        res.append(im)
    idx = im - 1

print(*res)
    