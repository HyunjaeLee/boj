a, b = map(int, input().split())
if a > b:
    a, b = b, a
print(max(b-a-1, 0))
for i in range(a+1, b):
    print(i, end=' ')
