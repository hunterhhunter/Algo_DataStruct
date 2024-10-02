n = int(input())

lst = []
w, b = 0, 0

for _ in range(n):
    lst.append(list(map(int, input().split())))


# 인덱싱은 맨날해도 헷갈린다....
# 기존 2차원 좌표계와 맨날 헷갈리는듯..!!

def divide(x, y, N):
    global w, b
    cur_color = lst[x][y]
    gan = N // 2
    for i in range(x, x+N):
        for j in range(y, y+N):
            if cur_color != lst[i][j]:
                # 사분할
                divide(x, y, gan) # 2사분면
                divide(x+gan, y, gan) # 1사분면
                divide(x, y+gan, gan) # 3사분면
                divide(x+gan, y+gan, gan) # 4 사분면
                return
            
    # 흰색이면 자르기
    if cur_color == 0: 
        w += 1
    else: # 파랑이면 갯수 세기
        b += 1

divide(0, 0, n)
print(w)
print(b)