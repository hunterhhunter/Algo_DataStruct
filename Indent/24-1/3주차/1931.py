import sys
sinput = sys.stdin.readline
inp = int(sinput())
lis = []
count = 1
for _ in range(inp):
    lis.append(tuple(map(int, ().split())))

lis.sort(key= lambda x : (x[1], x[0])) # 회의 시간이 적은 순서대로
x = lis[0][1] # 초기값 설정

for i in lis[1:]:
    if x <= i[0]: # 이미 정렬된 상태이기에 끝나면 바로 시작하게 하면 된다.
        count += 1
        x = i[1]
print(count)