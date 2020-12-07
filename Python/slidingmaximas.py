# t test-cases 
# problem statement: google kickstart "record breaker"
t = int(input())
for _ in range(t):
    arr = list(map(int,input().split()))
    max_i = 0
    count = 0
    for i in range(len(arr)-1):
        if arr[i]>arr[i+1] and arr[i] > max_i:
            max_i = arr[i]
            count = count + 1
    print(count)
