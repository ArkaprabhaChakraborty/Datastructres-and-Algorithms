'''
You are given a set A and n other sets.
Your job is to find whether set  is a strict superset of each of the  sets.
Print True, if  is a strict superset of each of the  sets. Otherwise, print False.
A strict superset has at least one element that does not exist in its subset.

Example
Set(1,3,4) is a strict superset of set(1,3).
Set(1,3,4) is not a strict superset of set(1,3,4).
Set(1,3,4) is not a strict superset of set(1,3,5).
'''


super = input().split() #Accept Super Set
super = list(map(int,super))
super = set(super)
t = int(input())
x = [] 
for i in range(t):
    a = input().split()
    a = list(map(int,a))
    a = set(a)
    x.append(super.issuperset(a))
print(all(x))
