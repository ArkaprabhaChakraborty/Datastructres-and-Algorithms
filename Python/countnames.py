'''
You are given a long string as input in each testcase, 
containing any ASCII character. Your task is to find out 
the number of times SUVO and SUVOJIT appears in it.

Input Format
The first line contains the number of testcases, T. Next, T lines follow each containing a long string S.

Output Format
For each long string S, display the no. of times SUVO and SUVOJIT appears in it.

SAMPLE INPUT 

3
SUVOJITSU
651SUVOMN
$$$$$SUVOSUVOJIT$$$$$

SAMPLE OUTPUT 

SUVO = 0, SUVOJIT = 1
SUVO = 1, SUVOJIT = 0
SUVO = 1, SUVOJIT = 1
'''

t = int(input())
for i in range(t):
    s = input()
    c = s.count("SUVO")
    d = s.count("SUVOJIT")
    print("SUVO = %d, SUVOJIT = %d"%(c-d,d))
    