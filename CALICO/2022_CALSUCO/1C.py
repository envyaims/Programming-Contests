from sys import stdin, stdout
from math import isqrt, floor
for _ in  range(int(stdin.readline())):
    n = int(stdin.readline())
    ans = (isqrt(1 + 8 * n) - 1) // 2
    stdout.write(str(ans)+"\n")
