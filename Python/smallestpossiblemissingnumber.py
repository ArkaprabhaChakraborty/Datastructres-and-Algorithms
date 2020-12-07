t = int(input())
for _ in range(t):
    arr = list(map(int,input().split()))
    check = [False]*(len(arr)*len(arr)*len(arr))
    for i in range(len(arr)):
        if arr[i] >= 0:
            check[arr[i]] = True
    for i in range(len(check)):
        if check[i] == False:
            print(i)
            break
