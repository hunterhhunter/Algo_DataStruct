n = int(input())

lst = list(map(int, input().split()))
speed = 0 # 마지막 속력
answer = 0

for i in range(n-1, -1, -1):
    if lst[i] > speed:  # 역방향에서 다음 블럭의 제한속도가 현재보다 클 때
                        # -> 현재 속도 + 1이 다음에서 낼 수 있는 max
        speed += 1
    else:              #  역방향에서 다음 블럭의 제한속도가 더 작을 때는 다음 블럭의 제한 속도가 max
        speed = lst[i]

    answer += speed

print(answer)