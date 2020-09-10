from collections import defaultdict

arr = [1, 1, 1, 5, 5, 2, 3, 4]

d = defaultdict(int)

for n in arr:
    d[n] += 1

print(d)

