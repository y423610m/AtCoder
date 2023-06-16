n = int(input())

ans = "Yes"
i = 2
while i*i<=n:
    if n%i==0: ans = "No"
    i += 1
print(ans)