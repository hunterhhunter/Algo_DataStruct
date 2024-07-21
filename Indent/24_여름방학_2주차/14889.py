n = int(input())
total = [list(map(int, input().split())) for _ in range(n)]

visit = [False for _ in range(n)] # 선수 개인별 방문을 체크하는 리스트

min_value = 100000000

def tomsac(depth, idx):
    global min_value

    if depth == n // 2: # 절반 들렀을 때
        power1, power2 = 0, 0
        for i in range(n):
            for j in range(n):
                if visit[i] and visit[j]: # visit[i] = True이면 i번째 사람은 스타트팀에 속함
                    power1 += total[i][j] # 들른 사람 -> 스타트팀에 속함
                elif not visit[i] and not visit[j]:
                    power2 += total[i][j] # 안들른 사람 -> 스타트팀에 속하지 않음
        min_value = min(min_value, abs(power1-power2))
        return
    
    for i in range(idx, n):
        if not visit[i]:
            visit[i] = True
            tomsac(depth+1, i+1)
            visit[i] = False

tomsac(0, 0)
print(min_value)