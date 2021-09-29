v = int(input())
a = input().count('A')
b = v - a
if a > b:
    print('A')
elif a < b:
    print('B')
else:
    print('Tie')
