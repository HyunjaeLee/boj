a = sorted(map(int, input().split()))
print(*map(lambda x: a[ord(x)-65], input()))
