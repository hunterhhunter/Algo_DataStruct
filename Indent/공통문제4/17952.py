import sys
sinput = sys.stdin.readline

n = int(sinput())
remain = []
score = 0

for i in range(n):
    tf = list(map(int, sinput().split()))
    if tf[0] == 1:
        remain.append([tf[1], tf[2]]) # 과제는 일단 집어넣기

    if remain: # 과제가 남았네?
        remain[-1][1] -= 1 # 일단 해
        if remain[-1][1] == 0: # 다했다!
            score += remain[-1][0] # 점수 얻기
            remain.pop() # 한 과제는 세상의 저편으로
print(score)