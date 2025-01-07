n = int(input())
finish = False

def isgood(string: str):
    length = len(string)
    for i in range(2, length//2+1):
        for j in range(0, length - i*2 + 1):
            if string[j:j+i] == string[i+j:2*i+j]:
                return False
    
    return True

def recursion(string:str):
    global n, finish
    if finish == True:
        return
    if len(string) == n:
        print(string)
        finish = True
        return
    
    for i in range(1, 4):
        if string[-1] == str(i):
            continue
        substring = string+str(i)
        if isgood(substring):
            recursion(substring)
        substring = substring[:-1]

recursion("1")