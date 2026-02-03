a, b, c = map(int, input().split())

sum = a + b + c
avg = int(sum / 3)
c = sum - avg

print(sum, avg, c, sep = '\n')
