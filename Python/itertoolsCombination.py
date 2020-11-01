'''
itertools.combinations(iterable, r)
This tool returns the r length subsequences of elements from the input iterable.
Combinations are emitted in lexicographic sorted order. 
So, if the input iterable is sorted, the combination tuples will be produced in sorted order.

You are given a string S.
Your task is to print all possible combinations, up to size k, of the string S in lexicographic sorted order.
'''

from itertools import combinations
s,x = input().split()
x = int(x)
for i in range(x):
   h = combinations(sorted(s),i+1)
   for j in h:
    r = ''.join(j)
    print(r)
