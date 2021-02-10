m,n = map(int,input().split())
r = []
k = 0
l = 0
for i in range(m):
    c = []
    for j in range(n):
        x = int(input())
        c.append(x)
    r.append(c)
print(r)
while k < m and l < n:
    for i in range(k,m):
        print(r[k][i],end = " ")
    k = k + 1
    for i in range(l,n):
        print(r[i][n-1],end = " ")
    n = n - 1
    if k < m:
        for i in range(n - 1, (l - 1), -1): 
            print(r[m - 1][i], end=" ") 
        m -= 1
    if l < n:
        for i in range(m-1,k-1,-1):
            print(r[i][l],end = " ")
        l = l + 1
