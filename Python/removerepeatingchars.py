s = input()
s = list(s.rstrip())
l = []
j = 0
for i in range(len(s)):
    if s[j] != s[i]:
        j = j + 1
        s[j] = s[i]
r = ''.join(s[:j+1])
print(r)