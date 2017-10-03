n, m = map(int, raw_input().split())

if n > 2 : 
	if n <= m :
		print 1
	elif n % 2 == 0 and n / 2 <= m:
		print 2
	else :
		print -1
elif n == 2 :
	if m >= 2 : 
		print 1 
	elif m == 1 :
		print 2
	else :
		print -1
