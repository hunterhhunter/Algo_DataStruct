a, b = map(int, input().split())

yose = []
lis = [i for i in range(1, a+1)]
cnt = 0

while True:
    if len(yose) == a:
        print("<", end='')
        for i in yose[:-1]:
            print(f"{i}, ", end='')
        print(f"{yose[-1]}>", end='')
        break
    else:
        for i in range(b-1):
            lis.append(lis[cnt+i])
        cnt += b-1
        yose.append(lis[cnt])
        cnt += 1