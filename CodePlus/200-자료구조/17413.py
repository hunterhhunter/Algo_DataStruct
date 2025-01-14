inp = input()
stack = []
flag = False

# 핵심은 flag변수로 뒤집을 때와 뒤집지 않을 때를 구분하는 것것
for each in inp:
    if each == "<":
        while stack:
            print(stack.pop(), end='')
        print(each, end='')
        flag = True
    elif each == ">":
        print(each, end='')
        flag = False
    elif each == " ":
        while stack:
            print(stack.pop(), end='')
        print(" ", end='')
    else:
        if flag:
            print(each, end='')
        else:
            stack.append(each)
while stack:
    print(stack.pop(), end='')
    