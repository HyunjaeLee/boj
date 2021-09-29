n = int(input())
for i in range(1, 2*n):
    x = abs(n-i)
    print('*'*(n-x) + ' '*(2*x) + '*'*(n-x))
