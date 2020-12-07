'''
you're given the maximum speed of N cars in the order they entered the long straight segment of the circuit. 
Each car prefers to move at its maximum speed. If that's not possible because of the front car being slow, 
it might have to lower its speed. It still moves at the fastest possible speed while avoiding any collisions. 
For the purpose of this problem, you can assume that the straight segment is infinitely long.

Count the number of cars which were moving at their maximum speed on the straight segment.

Input
The first line of the input contains a single integer T denoting the number of test cases to follow. 
Description of each test case contains 2 lines. The first of these lines contain a single integer N, 
the number of cars. The second line contains N space separated integers, 
denoting the maximum speed of the cars in the order they entered the long straight segment.

Output
For each test case, output a single line containing the number of cars which were moving at their maximum speed 
on the segment.

Input:
3
1
10
3
8 3 6
5
4 5 1 2 3

Output:
1
2
2
'''
t = int(input())
for w in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    count = 0
    max = 9999999
    for i in range(len(a)):
        if max >= a[i]:
            count = count + 1
            max = a[i]
    print(count)
