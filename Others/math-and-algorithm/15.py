a,b = map(int, input().split())

ans = 1
d = 2
while d*d<=a:
    while a%d==0:
        a //=d
        if b%d==0:
            b//=d
            ans *= d
    d += 1

if a!=d and b%a==0:
    ans *= a

print(ans)