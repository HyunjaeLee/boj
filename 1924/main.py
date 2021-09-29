import datetime
print(['MON','TUE','WED','THU','FRI','SAT','SUN'][datetime.datetime(2007,*map(int,input().split())).weekday()])