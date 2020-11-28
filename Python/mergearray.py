# Let's assume NA elements to be -12345678 

def mergearray(n,m):
    l = []
    n_len = len(n)
    m_len = len(m)
    i = 0
    j = 0
    for k in range(n_len):
        if n[k] != -12345678:
            l.append(n[k])
    l.append(12345678)
    for k in range(n_len):
        if l[i] <= m[j]:
            n[k] = l[i]
            i = i + 1
        else:
            n[k] = m[j]
            j = j + 1    


if __name__ == '__main__':
    print("Enter Array N:")
    n = list(map(int,input().split()))
    print("Enter Array M:")
    m = list(map(int,input().split()))
    mergearray(n,m)
    print(n)

