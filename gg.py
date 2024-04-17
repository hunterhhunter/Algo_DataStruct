def selfnum(num: int) -> int:
    sum = num
    while num != 0:
        sum += num%10;
        num //= 10;
    return sum

arr = [1 for _ in range(10001)]
for i in range(1, 10001):
    num = selfnum(i)
    if num < 10001:
        arr[num] = 0

for i in range(1, 10001):
    if arr[i] == 1:
        print(i)