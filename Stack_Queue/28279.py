from collections import deque
import sys

sinput = sys.stdin.readline

queue = deque()
num = int(sinput())

for _ in range(num):
    inp = list(map(int, sinput().split()))

    if inp[0] == 1:
        queue.appendleft(inp[1])
    elif inp[0] == 2:
        queue.append(inp[1])
    elif inp[0] == 3:
        if queue:
            print(queue.popleft())
        else:
            print(-1)
    elif inp[0] == 4:
        if queue:
            print(queue.pop())
        else:
            print(-1)
    elif inp[0] == 5:
        print(len(queue))
    elif inp[0] == 6:
        if queue:
            print(0)
        else:
            print(1)
    elif inp[0] == 7:
        if queue:
            print(queue[0])
        else:
            print(-1)
    elif inp[0] == 8:
        if queue:
            print(queue[-1])
        else:
            print(-1)