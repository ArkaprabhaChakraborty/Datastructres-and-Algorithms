'''Writing a program to count the number of bits that are set to 1 in a positive integer'''

t = int(input("Enter No of test cases: "))
for _ in range(t):
    n = int(input("Enter number: "))
    numbits = 0
    while(n):
        x = int(n % 2)
        numbits = numbits + (x & 1) 
        n = n // 2
    print(numbits)
