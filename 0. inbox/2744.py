inp = input()

for each in inp:
    if ord(each) <= ord("Z") and ord(each) >= ord("A"):
        print(chr(ord(each)+32), end='')
    else:
        print(chr(ord(each)-32), end='')