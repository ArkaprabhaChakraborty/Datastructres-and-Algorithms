'''Let us consider a function Z. For any positive integer N, Z(N) is the number of zeros at the end of the decimal 
form of number N!. They noticed that this function never decreases. If we have two numbers N1<N2, then Z(N1) <= Z(N2). 
It is because we can never "lose" any trailing zero by multiplying by any positive number. We can only get new and new zeros. 
The function Z is very interesting, so we need a computer program that can determine its value efficiently.

Sample Input:
6
3
60
100
1024
23456
8735373

Sample Output:
0
14
24
253
5861
2183837

'''

t = int(input())
for i in range(t):
    x = int(input())
    count = 0
    while(x//5):
        count = count + x//5
        x = x//5
    print(count)
