import numpy as np

N = int(input())
A = list(map(int,input().split()))

ans = A[0]

for a in A:
    ans = np.gcd(a,ans)

print(ans)