s = input()
s = s.lower()
l = [0]*26
for i in range(len(s)):
    l[ord(s[i])-97] = l[ord(s[i])-97] + 1
maxit = 0
ind = 0
for i in range(len(l)):
    if maxit < l[i]:
        maxit = l[i]
        ind = i
ind = chr(ind+97)
print(ind + " %d"%(maxit))
