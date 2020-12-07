'''
Given a non-empty list of positive integers l and a target positive integer t, 
write a function solution(l, t) which verifies if there is at least one 
consecutive sequence of positive integers within the list l (i.e. a contiguous sub-list) 
that can be summed up to the given target positive integer t (the key) 
and returns the lexicographically smallest list 
containing the smallest start and end indexes where this sequence can be found, 
or returns the array [-1, -1] in the case that there is no such sequence 

For example, given the broadcast list l as [4, 3, 5, 7, 8] and the key t as 12, 
the function solution(l, t) would return the list [0, 2] because the list l contains 
the sub-list [4, 3, 5] starting at index 0 and ending at index 2, for which 4 + 3 + 5 = 12, 
even though there is a shorter sequence that happens later in the list (5 + 7). 
On the other hand, given the list l as [1, 2, 3, 4] and the key t as 15, 
the function solution(l, t) would return [-1, -1] because there is no sub-list of list l 
that can be summed up to the given target value t = 15.

our code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Python cases --
Input:
solution.solution([1, 2, 3, 4], 15)
Output:
    -1,-1

Input:
solution.solution([4, 3, 10, 2, 8], 12)
Output:
    2,3

'''

def solution(l, t):
    start = 0
    while start < len(l):
        for stop in range(start, len(l)):
            s = sum(l[start:stop+1])
            if s == t:
                return [start, stop]
            elif s > t:
                break
        start += 1
    