mod = 100

N = input()
A = map(int,input().split())
ans = 0
for a in A:
    ans += a
    ans %= mod
print(ans)