import datetime
y, m, d = map(int, raw_input().split('/'))
t = datetime.date(y, m, d)

while t.year % (t.month * t.day) != 0:
	t += datetime.timedelta(1)

print"%04d/%02d/%02d" % (t.year, t.month, t.day)

