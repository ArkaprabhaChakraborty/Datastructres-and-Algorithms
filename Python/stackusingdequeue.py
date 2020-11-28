#stack using collections.deque ... faster than built-in list
from collections import deque as dq
stack = dq()
print("Enter elements(space separated) to push in stack")
l = list(map(int,input().split()))
for i in l:
    stack.append(i)
print("Popping out :")
for i in range(len(stack)):
    print(stack.pop())
