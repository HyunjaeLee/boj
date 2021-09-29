cur = ''
sum = 0
for r in input():
    if r == cur:
        sum += 5
    else:
        cur = r
        sum += 10
print(sum)
