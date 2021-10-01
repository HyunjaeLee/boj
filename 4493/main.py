import sys
read = sys.stdin.readline
for _ in range(int(read())):
    cnt1 = 0
    cnt2 = 0
    for _ in range(int(read())):
        p1, p2 = read().split()
        if p1 == 'R' and p2 == 'S':
            cnt1 += 1
        elif p1 == 'S' and p2 == 'P':
            cnt1 += 1
        elif p1 == 'P' and p2 == 'R':
            cnt1 += 1
        elif p2 == 'R' and p1 == 'S':
            cnt2 += 1
        elif p2 == 'S' and p1 == 'P':
            cnt2 += 1
        elif p2 == 'P' and p1 == 'R':
            cnt2 += 1
    if cnt1 > cnt2:
        print('Player 1')
    elif cnt1 < cnt2:
        print('Player 2')
    else:
        print('TIE')
