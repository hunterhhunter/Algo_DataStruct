import sys
sinput = sys.stdin.readline

n = int(sinput())
su = 0
xor = 0
for _ in range(n):
    a = list(map(int, sinput().split()))
    if a[0] == 1:
        su += a[1]
        xor ^= a[1]
    elif a[0] == 2:
        su -= a[1]
        xor ^= a[1] # XOR은 두 번 연산시 0 => 그러므로 이미 있는 수 ^ 지우려는 수를 하면 0이됨
    elif a[0] == 3:
        print(su)
    elif a[0] == 4:
        print(xor)