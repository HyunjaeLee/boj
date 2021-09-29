import sys
cnt = [0] * 26
for r in sys.stdin.read():
    if r != ' ' and r != '\n':
        cnt[ord(r)-97] += 1
most = max(cnt)
print(''.join(chr(i+97) for i, v in enumerate(cnt) if v == most))
