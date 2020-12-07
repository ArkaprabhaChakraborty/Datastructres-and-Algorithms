
t = int(input())
#t is the number of test cases
for _ in range(t):
    arr = list(map(int,input().split()))
    #initial difference ...problem statement has said that there are atleast 2 elements in the array 
    pd = arr[1] - arr[0]
    j = 2
    curr = 2 #current subarray length
    ans = 0
    while(j<len(arr)):
        if(pd == (arr[j] - arr[j-1])):
            curr = curr + 1
        else:
            pd = arr[j] - arr[j-1]
            curr = 2
        ans = max(ans,curr)
        j = j + 1
    print(ans)
    