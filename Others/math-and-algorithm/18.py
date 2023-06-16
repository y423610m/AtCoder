N = int(input())
A = list(map(int,input().split()))

mp = {}
#{100:0, 200:0, 300:0, 400:0}

ans = 0
for a in A:
    mp.setdefault(500-a,0)
    ans += mp[500-a]
    mp.setdefault(a,0)
    mp[a] += 1
print(ans)
#print(mp)