for i in range(100, 1000):
    for j in range(100, 1000):
        if i == j and j % 111 == 0:
            continue
        if i % 10 != j // 100:
            continue
        x = i // 10
        y = j % 100
        if i * y == x * j:
            print(f'{i} / {j} = {x} / {y}')
