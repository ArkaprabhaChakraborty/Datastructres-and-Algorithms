t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    l = [int(x) for x in s]
    a_count = 0
    a = 0
    b_count = 0
    b = 0
    t = True
    for i in range(len(l)):
        if i%2 !=0:
            if l[i] == 1:
                a_count = a_count + 1
            a = a+1
        else:
            if l[i] == 1:
                b_count = b_count + 1
            b = b + 1
        r_a = n - a
        r_b = n - b
        if a_count - b_count > r_b:
            print(i+1)
            break
        elif b_count - a_count > r_a:
            print(i+1)
            break
        elif a_count == b_count and i == (len(l)-1):
            print(i+1)        