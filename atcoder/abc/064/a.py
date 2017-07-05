a = map(int, raw_input().split())
d = a[0] * 100 + a[1] * 10 + a[2]
if d % 4 == 0:
	print "YES"
else:
	print "NO"