M = int(input())
N = int(input())
result = []
for i in range(1, 101):
    sq = i*i
    if sq < M:
        continue
    if sq > N:
        break;
    result.append(sq)
if result:
    print(sum(result))
    print(result[0])
else:
    print(-1)
