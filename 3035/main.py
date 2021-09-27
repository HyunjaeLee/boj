R, C, ZR, ZC = map(int, input().split())
news = [input() for _ in range(R)]
for s in news:
    zoom = ["" for _ in range(ZR)]
    for c in s:
        for i in range(ZR):
            zoom[i] += c*ZC
    for line in zoom:
        print(line)
