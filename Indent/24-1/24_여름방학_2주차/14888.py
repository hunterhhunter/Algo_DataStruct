# 수의 개수 입력받기
n = int(input())

# 수 입력 받기
lis = list(map(int, input().split()))

# 연산자 개수 입력
plus, minus, multiply, divide = map(int, input().split())

# 최댓값, 최솟값 초기화
max_value, min_value = -1e9, 1e9
# max, min에 들어갔을 때 같은 값이라면 앞에 값이 출력 -> 형이 다름을 인지해야함


# dfs 탐색
def tomsac(num, idx):
    global max_value, min_value, plus, minus, multiply, divide

    # idx 는 1부터 시작하기 때문에 같아질 경우 연산자를 다 쓴거임
    if idx == n:
        max_value = max(num, max_value)
        min_value = min(num, min_value)
        return
    else:
        # 더하기
        if plus > 0:
            plus -= 1
            tomsac(num + lis[idx], idx + 1)
            plus += 1
        # 빼기
        if minus > 0:
            minus -= 1
            tomsac(num - lis[idx], idx +1)
            minus += 1
        # 곱하기
        if multiply > 0:
            multiply -= 1
            tomsac(num * lis[idx], idx+1)
            multiply += 1
        # 나누기
        if divide > 0:
            divide -= 1
            tomsac(int(num / lis[idx]), idx+1)
            divide += 1

tomsac(lis[0], 1)

print(max_value)
print(min_value)