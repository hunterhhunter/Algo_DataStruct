from collections import deque
from itertools import combinations

n, m = map(int, input().split())

map = [list(map(int, input().split())) for _ in range(n)]

# 포인트
# 1. 각 치킨집에서의 거리를 구해 저장하는 3차원 리스트 생성
# 2. 집들의 좌표를 구하고 선정된 치킨집들끼리의 거리 중 최소를 선정
# 3. combination으로 가능한 모든 조합을 검사
# -> 3에서 처음에 그리디로 생각해 치킨거리가 가장 짧은 m개만 선정
# -> 바로 틀림
# 태그 까보니 브루트포스 있어서 바로 combination으로 선회

# => 사실 bfs안하고 치킨집과 집들간의 거리만 구하면 되는거라
# 멘하탄 거리 계산식 그대로 사용해도 되는거였음
# 쓸데없이 계산 많이 했네
# 근데 저장해두는게 각 조합마다 계속 계산할 필요가 없어서 좋은 것 같은데
# 음 시간은 별 차이가 없네요??

chicken_zip = [] # 치킨집 좌표
home_jwapwo = []

for i in range(n):
    for j in range(n):
        if map[i][j] == 2:
            chicken_zip.append((i, j))
        elif map[i][j] == 1:
            home_jwapwo.append((i, j))

chicken_distance_of_chicken = []
chicken_distance_of_home = [[[0 for _ in range(n)] for _ in range(n)] for _ in range(len(chicken_zip))] # 각 치킨집에서 가정집까지의 치킨거리 저장하는 공간간

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

# 모든 치킨집의 치킨거리 탐사
for num in range(len(chicken_zip)):
    dis = 0
    each = chicken_zip[num]
    i, j = each[0], each[1]
    queue = deque()
    queue.append(each)

    # 치킨거리 탐사
    while queue:
        jwapyo = queue.popleft()
        x, y = jwapyo[0], jwapyo[1]

        for k in range(4):
            nx, ny = x+dx[k], y+dy[k]
            if nx >= n or nx < 0 or ny >= n or ny < 0:
                continue
            if chicken_distance_of_home[num][nx][ny] != 0:
                continue
            chicken_distance_of_home[num][nx][ny] = chicken_distance_of_home[num][x][y] + 1

            if map[nx][ny] == 1:
                dis += chicken_distance_of_home[num][nx][ny]
            queue.append((nx, ny))
    
    # 한 치킨집의 치킨거리 탐사 완
    chicken_distance_of_chicken.append(num)

# 가능한 모든 치킨집 조합 생성
selected_chicken = list(combinations(chicken_distance_of_chicken, m))

# 가능한 모든 치킨집조합으로 치킨거리 재계산
chicken_distance = 10000000
for combi in selected_chicken:
    chicken_dist = 0
    for each_home in home_jwapwo:
        i, j = each_home[0], each_home[1]
        local_min = 200
        # 선정된 치킨집 중 가장 치킨거리가 짧은 거리를 선정
        for each_chicken in combi:
            local_min = min(local_min, chicken_distance_of_home[each_chicken][i][j])
        chicken_dist += local_min   
    chicken_distance = min(chicken_distance, chicken_dist)

print(chicken_distance)