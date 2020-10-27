
k = int(input())
a = input().split()
a = list(map(int,a))
b = set(a)
print(((sum(b)*k)-(sum(a)))//(k-1))
