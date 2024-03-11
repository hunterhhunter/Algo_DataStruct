import sys
sinput = sys.stdin.readline

def w(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:
        return 1
    
    if a > 20 or b > 20 or c > 20:
        return w(20, 20, 20)
    
    if lis[a][b][c] != 0:
        return lis[a][b][c]
    
    if a < b < c:
        lis[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
        return lis[a][b][c]
    
    lis[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
    return lis[a][b][c]

lis = [[[0 for _ in range(21)] for _ in range(21)] for _ in range(21)]

while True:
    a, b, c = map(int, sinput().rstrip().split())
    if a == -1 and b == -1 and c == -1:
        break
    ans = w(a, b, c)
    print("w(%d, %d, %d) = %d" %(a, b, c, ans))