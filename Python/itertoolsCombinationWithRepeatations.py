'''
itertools.combinations_with_replacement(iterable, r)
This tool returns r length subsequences of elements from the input iterable 
allowing individual elements to be repeated more than once.
Combinations are emitted in lexicographic sorted order. 
So, if the input iterable is sorted, the combination tuples will be produced in sorted order.

You are given a string S.
Your task is to print all possible size k replacement combinations of the string S in lexicographic sorted order.
'''

from itertools import combinations_with_replacement
s,x = input().split()
x = int(x)
h = combinations_with_replacement(sorted(s),x)
for i in h:
 r = ''.join(i)
 print(r)
 