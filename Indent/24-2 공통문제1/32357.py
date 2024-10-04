import sys
def isPalindrome(string: str):
    for i in range(len(string)//2):
        if string[i] != string[len(string)-1-i]:
            return False
    else:
        return True
    
n = int(sys.stdin.readline())
lst = []
res = []

for _ in range(n):
    inp = input()
    lst.append(inp)

for i in lst:
    if isPalindrome(i):
        res.append(i)

print(len(res) * (len(res)-1))