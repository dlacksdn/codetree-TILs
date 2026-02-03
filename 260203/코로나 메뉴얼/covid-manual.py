p1_d, p1_t = input().split()
p1_t = int(p1_t)

p2_d, p2_t = input().split()
p2_t = int(p2_t)

p3_d, p3_t = input().split()
p3_t = int(p3_t)

count = 0

if (p1_d == 'Y' and p1_t >= 37):
    count += 1

if (p2_d == 'Y' and p2_t >= 37):
    count += 1

if (p3_d == 'Y' and p3_t >= 37):
    count += 1

if (count >= 2):
    print('E')
else :
    print('N')