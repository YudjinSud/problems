def factor(x):
    j = 2
    res = []
    while (j * j <= x):
        while (x % j == 0):
            res.append(j)
            x /= j
        j += 1;

    if (x != 1):
        res.append(x)
    return res


x = int(input())

s = list(set(factor(x)))

y = 1
for j in s:
    y *= j

for j in s:
    j = int(j)

if s[0] != x:
    for i in range(40):
        if pow(int(i * y), int(i *y)) % x == 0:
            print(i * y)
            break
else:
    print(x)