# https://www.acmicpc.net/problem/2839

N = int(input())
n = 0
m = 0

while N > 0:
    if N % 5 == 0:
        n = int(N / 5)
        break
    else:
        N -= 3
        m += 1

if N < 0:
    print(-1)
else:
    print(n + m)
