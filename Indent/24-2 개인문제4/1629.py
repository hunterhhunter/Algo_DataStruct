A, B, C = map(int, input().split())

def bunhal(a, b):
    if b == 1:
        return a % C # 
    
    temp = bunhal(a, b//2) # 

    if b%2 == 0:
        return temp * temp % C
    else:
        return temp * temp * a % C
    
print(bunhal(A, B))

# 분할정복의 bottom up
# n을 이진수로 보고 진행

