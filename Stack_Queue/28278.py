import sys

input = sys.stdin.readline

stack = list()
num = int(input())

def push(x):
    stack.append(x)

def pop():
    if stack:
        print(stack.pop())
    else:
        print(-1)

def printlen():
    print(len(stack))

def isEmpty():
    if stack: print(0) 
    else: print(1)

def popprint():
    if stack: print(stack[-1])
    else: print(-1)

for i in range(num):
    infunc = list(map(int, input().split()))

    if infunc[0]==1:
        push(infunc[1])
    elif infunc[0]==2:
        pop()
    elif infunc[0]==3:
        printlen()
    elif infunc[0]==4:
        isEmpty()
    elif infunc[0]==5:
        popprint()