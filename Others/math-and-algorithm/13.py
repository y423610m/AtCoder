n = int(input())

ans1 = []
ans2 = []
d = 1
while d*d<=n:
    if n%d==0:
        ans1.append(d)
        if d*d!=n: ans2.append(n//d)
    d += 1

print(*ans1, end=" ")
print(*ans2[::-1])