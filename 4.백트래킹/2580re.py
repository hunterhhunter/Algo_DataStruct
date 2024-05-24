import sys
sinput = sys.stdin.readline
sudoku = []
zero = []
for y in range(9):
    sudoku.append(list(map(int, sinput().split())))
    for x in range(9):
        if sudoku[y][x] == 0:
            zero.append((x, y))

def row(y, n):
    for i in range(9):
        if sudoku[y][i] == n:
            return False
    return True

def column(x, n):
    for i in range(9):
        if sudoku[i][x] == n:
            return False
    return True

def nearby(x, y, n):
    dx = x//3 * 3
    dy = y//3 * 3
    for i in range(3):
        for j in range(3):
            if sudoku[dy+i][dx+j] == n:
                return False
    return True

def solve_sudoku(idx):
    if idx == len(zero):
        for y in range(9):
            print(*sudoku[y])
        exit(0) # 강제 종료로 백트래킹 완
    
    # 1부터 9까지 넣어버리기
    for i in range(1, 10):
        y = zero[idx][1]
        x = zero[idx][0]
        if row(y, i) and column(x, i) and nearby(x, y, i): # i가 맞냐?
            sudoku[y][x] = i # 맞네?
            solve_sudoku(idx+1) # 다음 것도 고려해봐
            sudoku[y][x] = 0 # 아니네.. ㅎㅎ.. ㅈㅅ.. ㅋㅋ..

solve_sudoku(0)

# 결국 참고해버림...