import sys
sinput = sys.stdin.readline

string = sinput().rstrip()
n = int(sinput())

lst = [[0] * 26] # 알파벳 배열 
lst[0][ord(string[0])-97] = 1 # 처음 문자의 위치에 1개 표시

for i in range(1, len(string)):
    lst.append(lst[i-1].copy()) # 배열 복사 후 추가
    lst[i][ord(string[i])-97] += 1 # 나온 문자의 위치에 1개 표기

for _ in range(n):
    alpha, start, end = sinput().split()
    start, end = int(start), int(end)
    if start == 0:
        print(lst[end][ord(alpha)-97]) # 시작이 0이면 n까지 나타난 개수 출력
    else:
        print(lst[end][ord(alpha)-97]-lst[start-1][ord(alpha)-97]) # 시작-1(index)부터 n까지 나타난 개수 출력