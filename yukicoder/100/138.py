a = map(int, raw_input().split('.'))
b = map(int, raw_input().split('.'))
if a[0] > b[0]:
	print 'YES'
elif a[1] > b[1] and a[0] == b[0]:
	print 'YES'
elif a[2] >= b[2] and a[1] == b[1] and a[0] == b[0]:
	print 'YES'
else:
	print 'NO'
