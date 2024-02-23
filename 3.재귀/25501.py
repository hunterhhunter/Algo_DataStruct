def recursion(string, start, end):
    global many
    if start >= end:
        return 1
    elif string[start] != string[end]:
        return 0
    else:
        many += 1
        return recursion(string, start+1, end-1)

def isPalindrome(string):
    global many
    many += 1
    return recursion(string, 0, len(string)-1)

for _ in range(int(input())):
    string = input()
    many = 0
    print(isPalindrome(string), many)
