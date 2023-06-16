n = int(input())


d = 2

while d*d<=n:
    while n%d==0:
        n /= d
        print(d, end=" ")
    if n==1: break
    d += 1

if n!=1:
    print(int(n))

print("")