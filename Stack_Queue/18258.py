import sys
sinput = sys.stdin.readline

queue = list()
num = int(sinput())
cnt = 0
for _ in range(num):
    inp = list(sinput().split())

    if inp[0] == "push":
        queue.append(int(inp[1]))
    elif inp[0] == "pop":
        if len(queue)-cnt == 0:
            print(-1)
        else:
            print(queue[cnt])
            cnt += 1
    elif inp[0] == "size":
        print(len(queue)-cnt)
    elif inp[0] == "empty":
        if len(queue)-cnt == 0:
            print(1)
        else:
            print(0)
    elif inp[0] == "front":
        if len(queue)-cnt != 0:
            print(queue[cnt])
        else:
            print(-1)
    elif inp[0] == "back":
        if len(queue)-cnt != 0:
            print(queue[-1])
        else:
            print(-1)