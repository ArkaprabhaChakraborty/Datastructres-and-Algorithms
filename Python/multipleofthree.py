'''
Consider a very long K-digit number N with digits d0, d1, ..., dK-1 (in decimal notation; 
d0 is the most significant and dK-1 the least significant digit). 
This number is so large that we can't give it to you on the input explicitly; 
instead, you are only given its starting digits and a way to construct the remainder of the number.

Specifically, you are given d0 and d1; for each i ≥ 2, 
di is the sum of all preceding (more significant) digits, 
modulo 10 — more formally, the following formula must hold: 

Determine if N is a multiple of 3

Input
The first line of the input contains a single integer T denoting the number of test cases. 
The description of T test cases follows.
The first and only line of each test case contains three space-separated integers K, d0 and d1.

Output
For each test case, print a single line containing the string "YES" (without quotes) 
if the number N is a multiple of 3 or "NO" (without quotes) otherwise.

Input:
3
5 3 4
13 8 1
760399384224 5 1

Output:
NO
YES
YES

'''

t = int(input())
for i in range(t):
    k,d_0,d_1 = map(int,input().split())
    tmp = d_0 + d_1
    ans = tmp
    s = (2 * tmp)%10 + (4 * tmp)%10 + (6 * tmp)%10 + (8 * tmp)%10
    k = k-2
    if(k > 0):
        ans = ans + tmp%10
        k = k - 1
    ans = ans + (k//4)*s
    k = k%4
    p = 2
    while(k):
        ans = ans + (p*tmp)%10
        p = (p * 2) % 10
        k = k - 1
    if ans%3 == 0:
        print(True)
    else:
        print(False)