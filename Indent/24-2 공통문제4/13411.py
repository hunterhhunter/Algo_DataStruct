import sys
input = sys.stdin.readline

n = int(input())

lst = [] # (로켓순서, 걸리는 시간)

# 정수로 해결하는 방법도 생각해보면 좋음
# cmp
for i in range(n):
    x, y, speed = map(int, input().split())
    distance = (x**2+y**2)**(0.5)
    sec = distance / speed
    lst.append((i+1, sec))

lst.sort(key = lambda x: (x[1], x[0]))

for i, j in lst:
    print(i)