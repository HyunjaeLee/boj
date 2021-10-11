a = [(int(input()), i) for i in range(1, 9)]
a.sort(reverse=True)
print(sum(a[i][0] for i in range(5)))
no = [a[i][1] for i in range(5)]
no.sort()
print(' '.join(map(str, no)))
