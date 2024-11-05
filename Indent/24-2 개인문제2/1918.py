expression = input()
stack = []
result = []
# priority dict
priority = {
    '+': 1,
    '-': 1,
    '*': 2,
    '/': 2,
    '(': 0,
    ')': 3
}

for i in expression: #문자열 순회
    if i in list(priority.keys()): # 딕셔너리는 in에서 key를 검색 -> 딕셔너리 검색하셈
        if i == '(':
            stack.append(i)
        elif i == ')':
            while True:
                if stack:
                    tmp = stack.pop()
                    if tmp == '(':
                        break
                    else:
                        result.append(tmp)
                else:
                    break
        else:
            while True:
                if stack:
                    tmp = stack.pop()
                    if priority[i] <= priority[tmp]:
                        result.append(tmp)
                    else:
                        stack.append(tmp)
                        stack.append(i)
                        break
                else:
                    stack.append(i)
                    break
    else: # 수 포함
        result.append(i)

for i in stack[::-1]:
    result.append(i)

# 보통은  while stack:
# result.append(stack.pop())
# 도서검색프로그램 - 

print(''.join(result))