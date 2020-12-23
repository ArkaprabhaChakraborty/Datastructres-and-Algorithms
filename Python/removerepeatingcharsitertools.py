import itertools as it
s = input()
r = []
for (keys,group) in it.groupby(s):
    r.append(keys)
r = ''.join(r)
print(r)