def ispar(s):
    stack = []
    decider = False
    for i in s:
        if i=='{' or i=='(' or i=='[':
            stack.append(i)
        if i==']' or i=='}' or i==')':
            try:
                x = stack.pop()
                if (x=='[' and i == ']') or (x=='{' and i=='}') or (x=='(' and i==')'):
                    continue
                else:
                    return False
            except:
                return False
    if(len(stack)==0):
        return True
    else:
        return False

if __name__ == '__main__':
    x = input()
    if ispar(x):
        print(True)
    else:
        print(False)