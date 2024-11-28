import sys
input = sys.stdin.readline

inp = int(input())

lst = [0 for _ in range(inp+2)]
lst[1] = 1 # 첫번째 질문은 예

for i in range(2, inp+2):
    yn, start, end = map(int, input().split())
    
    if (lst[end] - lst[start-1] == yn * (end-start+1)): #start~end까지 전부 같은 답이려면 조건
        print("Yes")
        lst[i] = lst[i-1] + 1 # 누적합
    else:
        print("No")
        lst[i] = lst[i-1] + 2 # 누적합