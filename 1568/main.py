N = int(input())
cnt = 0
while N > 0:
    i = 1
    while i <= N:
        N -= i
        cnt += 1
        i += 1
print(cnt)
