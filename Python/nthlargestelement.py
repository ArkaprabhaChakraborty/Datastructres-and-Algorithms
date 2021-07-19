'''
nth largest element using divide and conquer approach
'''


def partition(l,r,arr):
    j = l-1
    pivot = r
    while(l < pivot):
        if(arr[l]>arr[pivot]):
            j = j + 1
            temp = arr[j]
            arr[j] = arr[l]
            arr[l] = temp
        l = l + 1
    temp = arr[j+1]
    arr[j+1] = arr[pivot]
    arr[pivot] = temp
    return j+1

def nthsmallest(i,j,n,arr):
    k = 0
    if(i<=j):
        m = partition(i,j,arr)
        if(n < m):
            nthsmallest(i,m-1,n,arr)
        elif(n > m):
            nthsmallest(m+1,j,n,arr)
        elif(n == m):
            print(arr[m])

arr = list(map(int,input().split()))
k = int(input())
nthsmallest(0,len(arr)-1,k-1,arr)