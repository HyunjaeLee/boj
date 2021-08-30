from itertools import combinations
kns = list(map(int, input().split()))
while kns[0] > 0:
    cs = combinations(kns[1:], 6)
    for c in cs:
        print(" ".join(map(str, c)))
    print()
    kns = list(map(int, input().split()))
