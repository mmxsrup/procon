n, m = map(int, raw_input().split())
if n > 2 : 
	if n == m :
		print 1
	else :
		print -1
else :
	if m > 1 : 
		print n - 1
	else :
		print -1

