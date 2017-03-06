# coding: UTF-8
s = raw_input().decode("utf-8")

ans = 0;
tmp = 0;
for i in s:
	if i == u"…":
		tmp += 1
	else:
		tmp = 0;
	ans = max(ans, tmp);

print ans
