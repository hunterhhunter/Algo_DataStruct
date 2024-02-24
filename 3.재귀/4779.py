def cantor(string, n):
    gogo = list(string)
    if  n == 0:
        return gogo
    
    for i in range(3**(n-1), 2 * (3**(n-1))):
        gogo[i] = ' '
    
    for idx in range(0, 2*(3**(n-1))+1, 3**(n-1)):
        sss = cantor(''.join(gogo[idx:(3**(n-1))+idx]), n-1)
        gogo[idx:(3**(n-1))+idx] = sss
    
    return ''.join(gogo)

while True:
    try:
        n = int(input())
        can = '-' * (3**n)
        ddd = cantor(can, n)
        if n == 0:
            print('-')
        else:
            print(ddd)
    except EOFError:
        break