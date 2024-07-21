n = int(input())
lis = list(map(int, input().split()))
plus, minus, multiply, divide = list(map(int, input().split()))

max_value, min_value = -1e9, 1e9

def tomsac(num, idx):
    global max_value, min_value, plus, minus, multiply, divide

    if idx == n:
        max_value = max(max_value, num)
        min_value = min(min_value, num)
        return
    else:
        if plus > 0:
            plus -= 1
            tomsac(num + lis[idx], idx + 1)
            plus += 1
        if minus > 0:
            minus -= 1
            tomsac(num - lis[idx], idx +1)
            minus += 1
        if multiply > 0:
            multiply -= 1
            tomsac(num * lis[idx], idx+1)
            multiply += 1
        if divide > 0:
            divide -= 1
            tomsac(int(num / lis[idx]), idx+1)
            divide += 1

tomsac(lis[0], 1)

print(max_value)
print(min_value)