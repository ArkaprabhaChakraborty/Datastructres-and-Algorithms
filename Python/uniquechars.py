print("Enter String :")
s = input().lower()
l = []
flag = True
for i in range(26):
    l.append(0)
for i in range(len(s)):
    l[ord(s[i])-97] = l[ord(s[i])-97] + 1 
for i in l:
    if i < 2:
        continue
    else:
        flag = False
        break
if flag:
    print("Unique")
else:
    print("Not Unique")