'''
itertools.product()

This tool computes the cartesian product of input iterables.
It is equivalent to nested for-loops.
For example, product(A, B) returns the same as ((x,y) for x in A for y in B).

You are given two lists A and B. Your task is to compute their cartesian product X.
A = [1, 2]
B = [3, 4]

AxB = [(1, 3), (1, 4), (2, 3), (2, 4)]
'''
from itertools import product
a = input().split()
a = list(map(int,a))
b = input().split()
b = list(map(int,b))
x = list(product(a,b))
s = ""
for i in x:
    s = s + str(i)+" "
print(s)