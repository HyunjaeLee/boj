import itertools
l = [int(input()) for _ in range(9)]
for d in itertools.combinations(l, 7):
    if sum(d) == 100:
        for i in d:
            print(i)
