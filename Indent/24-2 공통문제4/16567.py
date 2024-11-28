import sys
input = sys.stdin.readline

n, m = map(int, input().split())

tile = list(map(int, input().split()))
tile = [0] + tile + [0]
cnt = 0

for i in range(1, n+1):
    if tile[i] == 0:
        continue
    else:
        if tile[i-1] == 0 and tile[i+1] == 1: # 양 옆 타일이 0 1인 경우
            cnt += 1
        elif tile[i-1] == 0 and tile[i+1] == 0: # 양 옆 타일이 0 0인 경우
            cnt += 1

for _ in range(m):
    lst = list(map(int, input().split()))
    if lst[0] == 0:
        print(cnt)
    else:
        if tile[lst[1]] == 1: # 이미 1인 경우
            continue
        else:
            tile[lst[1]] = 1;
            if tile[lst[1]-1] == 1 and tile[lst[1]+1] == 1: # 양 옆 타일이 1 1인 경우
                cnt -= 1
            elif tile[lst[1]-1] == 0 and tile[lst[1]+1] == 0: # 양 옆 타일이 0 0인 경우
                cnt += 1