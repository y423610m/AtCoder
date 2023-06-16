N, S = map(int,input().split())
ans = 0

for r in range(1,N+1):
    for b in range(1,N+1):
        if r+b<=S:
            ans += 1

print(ans)