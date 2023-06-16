N = 4
C = [list(map(float,input().split())) for i in range(N)]

def outer_prod(a,b,c):
    bc = c.copy()
    ba = a.copy()
    for i in range(2):
        bc[i] -= b[i]
        ba[i] -= b[i]
    return bc[0]*ba[1]-bc[1]*ba[0]

for i in range(N):
    if outer_prod(C[i], C[(i+1)%N], C[(i+2)%N])<0:
        print("No")
        exit()
print("Yes")