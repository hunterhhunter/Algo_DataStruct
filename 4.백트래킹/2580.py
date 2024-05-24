# 주변 xy +- 1씩의 8칸이 꽉 차있는지
# 가로가 8칸이 꽉 차있는지
# 세로가 8칸이 꽉 차있는지
# 입력 받으면서 0을 확인?
# 돌면서 확인?

from typing import Union, List

# 주변 순회
def search_nearby(sudoku: List[List[int]], x:int, y:int) -> Union[int, bool]:
    if x < 3 and y < 3:
        mapping = [(i, j) for i in range(3) for j in range(3)]
    elif x < 3 and 3 <= y < 6:
        mapping = [(i, j) for i in range(3) for j in range(3, 6)]
    elif x < 3 and 6 <= y < 9:
        mapping = [(i, j) for i in range(3) for j in range(6, 9)]
    elif 3 <= x < 6 and y < 3:
        mapping = [(i, j) for i in range(3, 6) for j in range(3)]
    elif 6 <= x < 9 and y < 3:
        mapping = [(i, j) for i in range(6, 9) for j in range(3)]
    elif 3 <= x < 6 and 3<= y < 6:
        mapping = [(i, j) for i in range(3, 6) for j in range(3, 6)]
    elif 3 <= x < 6 and 6<= y < 9:
        mapping = [(i, j) for i in range(3, 6) for j in range(6, 9)]
    elif 6 <= x < 9 and 3 <= y < 6:
        mapping = [(i, j) for i in range(6, 9) for j in range(3, 6)]
    elif 6 <= x < 9 and 6 <= y < 9:
        mapping = [(i, j) for i in range(6, 9) for j in range(6, 9)]
    num = 45
    for xy in mapping:
        if sudoku[xy[0]][xy[1]] == 0:
            if xy[0] == x and xy[1] == y:
                continue
            return False
        num -= sudoku[xy[0]][xy[1]]
    return num

# 가로 순회
def search_width(sudoku: List[List[int]], x:int, y:int) -> Union[int, bool]:
    num = 45
    for i in range(9):
        if i != x:
            if sudoku[y][i] == 0:
                return False
            num -= sudoku[y][i]
    return num

# 세로 순회
def search_height(sudoku: List[List[int]], x:int, y:int) -> Union[int, bool]:
    num = 45
    for i in range(9):
        if i != y:
            if sudoku[i][x] == 0:
                return False
            num -= sudoku[i][x]
    return num

sudoku = [list(map(int, input().split())) for _ in range(9)]
f_sudoku = [[0 for _ in range(9)] for _ in range(9)]
for i in range(9):
    for j in range(9):
        f_sudoku[i][j] = sudoku[i][j]

for y in range(9):
    for x in range(9):
        if sudoku[y][x] == 0:
            near = search_nearby(sudoku, y, x)
            width = search_width(sudoku, y, x)
            height = search_height(sudoku, y, x)
            if near:
                sudoku[y][x] = near
            elif width:
                sudoku[y][x] = width
            elif height:
                sudoku[y][x] = height

for ls in sudoku:
    for i in ls:
        print(i, end=' ')
    print()

for i in range(9):
    for j in range(9):
        print(f_sudoku[i][j] - sudoku[i][j], end=' ')
    print()