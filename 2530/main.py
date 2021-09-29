from datetime import datetime, timedelta
d=datetime(1,1,1,*map(int, input().split()))+timedelta(seconds=int(input()))
print(d.hour, d.minute, d.second)
