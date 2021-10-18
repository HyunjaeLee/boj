_, t = map(int, input().split())
acc = 0
cnt = 0
for a in map(int, input().split()):
    acc += a
    if acc > t:
        break
    cnt += 1
print(cnt)
