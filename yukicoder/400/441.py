a, b = map(int, raw_input().split())
if(a + b < a * b):
	print("P")
elif(a * b < a + b):
	print("S")
else:
	print("E")
