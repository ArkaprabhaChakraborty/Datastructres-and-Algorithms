'''
Consider the following:

A string, s , of length n where s = c0c1...cn-1.
An integer, k , where k is a factor of n.
We can split s into n/k subsegments where each subsegment, ti , consists of a contiguous block of  characters in . Then, use each  to create string  such that:

The characters in  are a subsequence of the characters in .
Any repeat occurrence of a character is removed from the string such that each character in  occurs exactly once. In other words, if the character at some index  in  occurs at a previous index  in , then do not include the character in string .
Given  and , print  lines where each line  denotes string .

Input Format

The first line contains a single string denoting .
The second line contains an integer, , denoting the length of each subsegment.

Constraints

, where  is the length of
It is guaranteed that  is a multiple of .
Output Format

Print  lines where each line  contains string .

Sample Input

AABCAAADA
3   
Sample Output

AB
CA
AD
Explanation

String  is split into  equal parts of length . We convert each  to  by removing any subsequent occurrences non-distinct characters in :

We then print each  on a new line.
'''





def merge_the_tools(string, k):
    u = [string[i:i+k] for i in range(0,len(string),k)]
    for j in u:
        s = set()
        x = ""
        for i in range(len(j)):
            z = j[i]
            if z not in s:
                x = x + z
                s.add(z)
        print(x)

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)