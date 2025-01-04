import sys
input = sys.stdin.readline

stack1 = list(input())[:-1]
stack2 = []
cursor = len(stack1)      # 인덱스의 앞쪽에 커서가 존재재

n = int(input())

for _ in range(n):
    command = list(input().split())
    len_of_stack = len(stack1) + len(stack2)

    if command[0] == "L":
        cursor -= 1
        if cursor < 0:
            cursor = 0
    elif command[0] == "D":
        cursor += 1
        if cursor > len_of_stack:
            cursor = len_of_stack
    elif command[0] == "B":
        if cursor == 0:
            continue
        elif cursor <= len(stack1):
            for _ in range(len(stack1)-cursor):
                stack2.append(stack1.pop())
            stack1.pop()
        elif cursor > len(stack1):
            for _ in range(cursor-len(stack1)-1):
                stack1.append(stack2.pop())
            stack2.pop()
        cursor -= 1
    elif command[0] == "P":
        if cursor <= len(stack1):
            for _ in range(len(stack1)-cursor):
                stack2.append(stack1.pop())
            stack1.append(command[1])
        else:
            for _ in range(cursor-len(stack1)):
                stack1.append(stack2.pop())
            stack2.append(command[1])
        cursor += 1
    
    #print(''.join(stack1) + ''.join(stack2[::-1]))
    #print(f"cursor: {cursor}")

print(''.join(stack1) + ''.join(stack2[::-1]))
