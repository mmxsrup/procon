x1, y1 = map(int, raw_input().split())
x2, y2 = map(int, raw_input().split())

if x1 == 0 and x2 == 0:
	print y1
elif y1 == 0 and y2 == 0:
	print x1
elif x1 % x2 == 0 and y1 % y2 == 0 and x2 != 0 and y2 != 0:
	print x1 + 1
else:
	if x1 >= y1:
		print y1 + (x1 - y1)
	else:
		print x1 + (y1 - x1)
