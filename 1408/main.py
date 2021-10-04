def parse():
    time = 0
    for t in map(int, input().split(':')):
        time = time * 60 + t
    return time
cur = parse()
begin = parse()
if cur < begin:
    remain = begin - cur
else:
    remain = 24*60*60 + begin - cur
print('%02d:%02d:%02d' % (remain//3600, remain//60%60, remain%60))
