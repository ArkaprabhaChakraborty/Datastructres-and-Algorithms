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
    for i in arr:
        max_ending_here = max_ending_here + i
        if max_ending_here<0 :
            max_ending_here = 0
        if max_so_far<max_ending_here:
            max_so_far = max_ending_here
    return max_so_far
n = int(input())
x = list(map(int,input().split()))
print(maxSubArraySum(x))
