'''
Lapindrome is defined as a string which when split in the middle, gives two halves having the same characters and same frequency of each character. If there are odd number of characters in the string, we ignore the middle character and check for lapindrome. For example gaga is a lapindrome, since the two halves ga and ga have the same characters with same frequency. Also, abccab, rotor and xyzxy are a few examples of lapindromes. Note that abbaab is NOT a lapindrome. The two halves contain the same characters but their frequencies do not match.
Your task is simple. Given a string, you need to tell if it is a lapindrome.

INPUT:

6
gaga
abcde
rotor
xyzxy
abbaab
ababc

OUTPUT:

YES
NO
YES
YES
NO
NO
'''

try:
    t = int(input())
    for i in range(t):
        s = input()
        n = len(s)
        flag = True
        z = []
        l = []
        for i in range(26):
            z.append(0)
            l.append(0)
        if n%2 == 0:
            for i in range(n//2):
                z[ord(s[i])-97]+=1
            for i in range((n//2),n):
                l[ord(s[i])-97]+=1
        else:
            for i in range(n//2):
                z[ord(s[i])-97]+=1
            for i in range((n//2)+1,n):
                l[ord(s[i])-97]+=1
        for i in range(26):
            if z[i] != l[i]:
                flag = False
        if flag:
            print("YES")
        else:
            print("NO")
except:
    pass