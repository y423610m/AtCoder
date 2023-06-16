X,Y,A,B = map(int,input().split())

ans = 0
while X<Y:
    if X*A<=X+B:
        X = X*A
        if X<Y:ans += 1
    else:
        #print(X,Y,A,B,(Y-1-X)//B*B)
        ans += (Y-1-X)//B
        X += (Y-1-X)//B*B
        break
    #print(X, ans)
print(ans)