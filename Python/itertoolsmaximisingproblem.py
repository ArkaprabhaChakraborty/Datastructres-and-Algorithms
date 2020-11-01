'''
You are given a function f(X) = X2. You are also given K lists. The ith list consists of Ni elements.
You have to pick one element from each list so that the value from the equation below is maximized:
S = (f(X1)+f(X2)+....+f(Xk))%M
Xi denotes the element picked from the ith list . Find the maximized value Smax obtained.
% denotes the modulo operator.
Note that you need to take exactly one element from each list, not necessarily the largest element. You add the squares of the chosen elements and perform the modulo operation. The maximum value that you can obtain, will be the answer to the problem.

Input Format
The first line contains 2 space separated integers K and M.
The next K lines each contains an integer Ni, denoting the number of elements in the ith list, followed by Ni space separated integers denoting the elements in the list.

Output Format
Output a single integer denoting the value Smax.

Sample Input
3 1000
2 5 4
3 7 8 9 
5 5 7 8 9 10 

Sample Output
206
'''

from itertools import product
K,M = map(int,input().split())
nums = []
for _ in range(K):
    row = map(int,input().split()[1:])
    nums.append(map(lambda x:x**2%M, row))
print(max(map(lambda x: sum(x)%M, product(*nums))))