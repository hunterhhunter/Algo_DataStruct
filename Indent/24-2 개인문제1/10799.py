inp = input()
stack = []
res = 0
stack.append(inp[0])
# print(stack)

for i in range(1, len(inp)):
    # print(inp[i])
    if inp[i] == ")":
        if inp[i-1]+inp[i] == "()":
            stack.pop()
            res += len(stack)
        else:
            res += 1
            stack.pop()
    else:
        stack.append(inp[i])
    # print(f"Stack: {stack} res: {res}")
print(res)