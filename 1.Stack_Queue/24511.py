import sys
from collections import deque
sinput = sys.stdin.readline

num = int(sinput())
qorstack = list(map(int, sinput().split()))
inside_element = list(map(int, sinput().split()))
len_su = int(sinput())
elements = list(map(int, sinput().split()))
gogo = deque()
tmp1 = 0
res = []

for i in range(num):
    if qorstack[i] == 0:
        gogo.append(inside_element[i])

for i in range(len(elements)):
    gogo.appendleft(elements[i])
    res.append(gogo.pop())

print(*res)

"""스택은 넣은게 그대로 나오므로 패스해도 됨
 -> 큐 만 남는데 큐끼리 연결하면 다시 커다란 큐가 됨
 """