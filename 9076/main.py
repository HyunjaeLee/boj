for _ in range(int(input())):
    s = sorted(map(int, input().split()))
    if s[3]-s[1] < 4:
        print(sum(s[1:4]))
    else:
        print('KIN')
