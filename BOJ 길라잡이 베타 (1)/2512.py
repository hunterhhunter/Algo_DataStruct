n = int(input())
lst = list(map(int, input().split()))
total = int(input())

ans = 0

start = 0
end = max(lst)+1

# 요점은 예산한정액 자체를 이분탐색하는 것이다.
# 이분탐색에서 start+1 < end인 경우에만 반복하도록 하면 된다.
# end = max(lst)+1로 정의하는 것은 max(lst)가 포함되도록 해야하기 때문이다.
# 예를 들자면 정답은 100이고 start, end = 0, 100인 경우 100까지 포함시켜야하기 때문
# +1안하면 99에서 멈춘다.

while True:
    tmp_ans = 0
    mid = int((start + end) / 2)

    if start+1 >= end:
        print(mid)
        break

    for each in lst:
        if each > mid:
            tmp_ans += mid
        else:
            tmp_ans += each

    if tmp_ans > total:
        end = mid
    else:
        start = mid