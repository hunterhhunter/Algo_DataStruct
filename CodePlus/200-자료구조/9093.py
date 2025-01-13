n = int(input())

for _ in range(n):
    inp = list(input().split())
    for each in inp:
        print(each[::-1], end=' ')
    print()