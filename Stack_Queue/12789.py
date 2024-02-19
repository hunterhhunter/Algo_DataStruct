num = int(input())

lis = list(map(int, input().split()))
stack = []
who = 1

for i in lis:
    if i == who:
        who += 1
    else:
        stack.append(i)

    while True:
        if stack:
            if stack[-1] == who:
                stack.pop()
                who += 1
            else:
                break
        else:
            break

if who == num+1:
    print("Nice")
else:
    print("Sad")