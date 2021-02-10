#Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
'''
Input:
N = 5
arr[] = {1,2,3,-2,5}
Output: 9
Explanation: Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.
'''

def maxSubArraySum(arr):
    ##Your code here
    max_so_far = 0
    max_ending_here = 0
    best_start = 0
    best_end = 0
    for i in range(len(arr)):
        if max_ending_here <= 0 :
            max_ending_here = arr[i]
            current_start = i
        else:
            max_ending_here = max_ending_here + arr[i]
        if max_so_far<max_ending_here:
            max_so_far = max_ending_here
            best_start = current_start
            best_end = i+1 #to make best_end exclusive
    return max_so_far, best_start, best_end
n = int(input())
x = list(map(int,input().split()))
y,l,r = maxSubArraySum(x)
print(y)
print(x[l:r])
