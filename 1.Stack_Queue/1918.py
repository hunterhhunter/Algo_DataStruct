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

for i in expression:
    if i in list(priority.keys()):
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
    else:
        result.append(i)

for i in stack[::-1]:
    result.append(i)

print(''.join(result))