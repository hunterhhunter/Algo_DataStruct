import sys
sinput = sys.stdin.readline

while True:
    st = sinput()
    aa = ''
    stack = list()
    if st==".":
        break

    for i in st:
        if i in "()[]":
            aa += i

    for i in aa:
        if i in "([":
            stack.append(i)
        else:
            if i == ")":
                if len(stack) > 0 and stack[-1] == "(":
                    stack.pop()
                else:
                    stack.append(i)
                    break
            else:
                if len(stack) > 0 and stack[-1] == "[":
                    stack.pop()
                else:
                    stack.append(i)
                    break
        
    if stack:
        print('no')
    else:
        print('yes')