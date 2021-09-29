n = int(input())
while n != -1:
    div = []
    for i in range(1, n):
        if n % i == 0:
            div.append(i)
    if sum(div) == n:
        print(f'{n} = ' + ' + '.join(map(str, div)))
    else:
        print(f'{n} is NOT perfect.')
    n = int(input())
