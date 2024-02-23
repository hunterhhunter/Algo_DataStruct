def factorial(n: int):
    if n < 2:
        return 1
    else:
        return n * factorial(n-1)

n = int(input())

print(factorial(n))