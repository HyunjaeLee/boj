from math import factorial
f = factorial(int(input()))
cnt = 0
while f%10 == 0:
    cnt += 1
    f //= 10
print(cnt)
