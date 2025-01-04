# 중요한 아이디어는 스택을 2개 쓸 것
# 또, 현재 커서 기준으로 
# 왼쪽에 있는 것, 오른쪽에 있는 것으로 스택이 나뉜다는 것을 알 것
import sys
input = sys.stdin.readline

stack1 = list(input())[:-1]
stack2 = []

n = int(input())

for _ in range(n):
    command = list(input().split())

    if command[0] == "L" and stack1:
        stack2.append(stack1.pop())
    elif command[0] == "D" and stack2:
        stack1.append(stack2.pop())
    elif command[0] == "B" and stack1:
        stack1.pop()
    elif command[0] == "P":
        stack1.append(command[1])
    #print(''.join(stack1) + ''.join(stack2[::-1]))
    #print(f"cursor: {cursor}")

print(''.join(stack1) + ''.join(stack2[::-1]))
