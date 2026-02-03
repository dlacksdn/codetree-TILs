a, b, c = map(int, input().split())

result = a if (a < b) else b
result = result if (result < c) else c

print(result)