A = int(input())
B = int(input())
C = int(input())
product = A * B * C
counts = [0] * 10
while product > 0:
    counts[product%10] += 1
    product //= 10
for count in counts:
    print(count)
