t = int(input())
for _ in range(t):
    arr = list(map(int,input().split()))
    idx = [-1]*(len(arr)*len(arr))
    mini = 9999999999
    for i in range(len(arr)):
        if idx[arr[i]] == -1:
            idx[arr[i]] = i
        else:
            mini = min(mini,idx[arr[i]])
    print("%d at index %d"%(arr[mini],mini))
