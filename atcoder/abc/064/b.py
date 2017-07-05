N = input()
a = map(int, raw_input().split())
a.sort()
print a[-1] - a[0]
