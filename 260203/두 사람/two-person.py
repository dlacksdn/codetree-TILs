a, b = input().split()
a = int(a)

c, d = input().split()
c = int(c)

if (a < 19 and c < 19 or b == 'W' and d == 'W'):
    print(0)
elif (a >= 19 and b == 'M' or c >= 19 and d == 'M'):
    print(1)