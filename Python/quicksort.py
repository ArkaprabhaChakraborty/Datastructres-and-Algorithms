# importing the sys module 
import sys 
  
# the setrecursionlimit function is 
# used to modify the default recursion 
# limit set by python. Using this,  
# we can increase the recursion limit 
# to satisfy our needs 
  
sys.setrecursionlimit(10**6) 

def partition(a,l,r):
    pivot = r
    i = l-1 #hotfix to ensure we don't skip the first element
    while(l < r):
        if(a[l]<a[pivot]):
            i = i+1 # i can be at -1  
            temp = a[i] 
            a[i] = a[l]
            a[l] = temp 
        #increment j till pivot-1 as we want to position pivot element
        l = l + 1
    temp = a[i+1]
    a[i+1] = a[pivot]
    a[pivot] = temp
    return (i+1)

def quicksort(a,l,r):
    if l < r:
        mid = partition(a,l,r)
        #since mid has the correct element at its position
        quicksort(a,l,mid-1)
        quicksort(a,mid+1,r)

if __name__=='__main__':
    print("Enter Unsorted array :")
    arr = list(map(int,input().split()))
    print(arr)
    quicksort(arr,0,len(arr)-1)
    print("Sorted Array :")
    print(arr)


