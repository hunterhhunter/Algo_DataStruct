n = int(input())
inp = input()
stack = []
num = []
dic = {chr(each):0 for each in range(65, 91)}

for i in range(n):
    nst = int(input())
    dic[chr(i+65)] = nst

for each in inp:
    if each == "+":
        first = stack.pop()
        second = stack.pop()
        stack.append(second+first)
    elif each == "-":
        first = stack.pop()
        second = stack.pop()
        stack.append(second-first)
    elif each == "/":
        first = stack.pop()
        second = stack.pop()
        stack.append(second/first)
    elif each == "*":
        first = stack.pop()
        second = stack.pop()
        stack.append(second*first)
    else:
        stack.append(dic[each])

print("{:.2f}".format(stack[0]))