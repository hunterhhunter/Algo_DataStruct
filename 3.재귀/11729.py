n = int(input())

movements = []
cnt = 0

def hanoi(n, start, end):
    global cnt
    cnt += 1
    remains = 6 - start - end

    if n == 1:
        movements.append((start, end))
    else:
        hanoi(n-1, start, remains)
        movements.append((start, end))
        hanoi(n-1, remains, end)

hanoi(n, 1, 3)
print(cnt)
for a, b in movements:
    print(a, b)
