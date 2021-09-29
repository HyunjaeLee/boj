n = int(input())
cnt = [0] * 5
for _ in range(n):
    x, y = map(int, input().split())
    if x > 0 and y > 0:
        cnt[1] += 1
    elif x < 0 and y > 0:
        cnt[2] += 1
    elif x < 0 and y < 0:
        cnt[3] += 1
    elif x > 0 and y < 0:
        cnt[4] += 1
    else:
        cnt[0] += 1
for i in range(1, 5):
    print(f'Q{i}: {cnt[i]}')
print(f'AXIS: {cnt[0]}')
