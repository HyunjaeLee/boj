result = int(input())
op = input()
while op != '=':
    x = int(input())
    if op == '+':
        result += x
    elif op == '-':
        result -= x
    elif op == '*':
        result *= x
    elif op == '/':
        result //= x
    op = input()
print(result)
