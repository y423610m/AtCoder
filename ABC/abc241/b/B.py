from collections import defaultdict
N,M = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

cnt = defaultdict(int)
for a in A:
    cnt[a] += 1

ans = "Yes"
for b in B:
    if cnt[b]<=0:
        ans = "No"
    cnt[b] -= 1
print(ans)