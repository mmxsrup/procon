n, m = map(int, raw_input().split())

flag = 1
if m == 0 :
	if n <= 2 :
		flag = 0
elif m == 1 :
	flag = 1
else :
	flag = 1

if flag :
	print "Possible"
else :
	print "Impossible"