def sum(n, base):
    result = 0
    while n > 0:
        result += n % base
        n //= base
    return result

for i in range(1000, 10000):
    sum10 = sum(i, 10)
    sum12 = sum(i, 12)
    sum16 = sum(i, 16)
    if sum10 == sum12 and sum12 == sum16:
        print(i)