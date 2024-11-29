n, k = map(int, input().split())
cnt = 0
suyul = list(map(int, input().split()))


for i in range(n//2):
    a, b = suyul[i], suyul[len(suyul)-1-i]
    difference = abs(a-b)
    tmp1 = difference

    tmp1 = 1 + ((min(a, b)+k)-max(a, b))
    tmp2 = (difference % k) + (difference // k)
    
    if tmp1 <= 0:
        cnt += min(difference, tmp2)
    else:
        cnt += min(difference, tmp1, tmp2)
print(cnt)