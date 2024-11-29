import sys
sys.setrecursionlimit(10**6)
cnt = 0

def dfs(node):
    visited[node] = True
    for i in info[node]:
        if not visited[i[0]]:
            visited[i[0]] = True
            distance[i[0]] += distance[node] + i[1]
            dfs(i[0])

n = int(input())
info = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]
distance = [0 for _ in range(n+1)]

for _ in range(n-1):
    a, b, c = map(int, input().split())
    info[a].append([b, c])
    info[b].append([a, c])

dfs(1)
print(max(distance))