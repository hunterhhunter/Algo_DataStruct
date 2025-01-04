import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    command = input().rstrip()
    len_of_array = int(input())
    array = input().rstrip()
    array = array[1:-1]
    
    if len(array) != 0:
        array = list(array.split(','))
    else:
        array = []
   
    #print("array: ", array)
    # D로 split 하고 R의 개수를 세면 되는거지!
    cnt = 0
    idx = 0
    for each in command:
        if each == "D":
            if not array or idx >= len(array):
                print("error")
                break
            else:
                if cnt % 2 == 0:
                    idx += 1
                else:
                    array.pop()
        else:
            cnt += 1
    else:
        if idx >= len(array):
            print("[]")
        else:
            if cnt % 2 == 0:
                print(f"[{','.join(array[idx:])}]")
            else:
                print(f"[{','.join(array[idx:][::-1])}]")