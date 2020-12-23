class Node:
    def __init__(self,data):
        self.left = None
        self.data = data
        self.right = None
        

def insert(root,x):
    if root is None:
        return Node(x)
    elif x < root.data:
        root.left = insert(root.left,x)
    else:
        root.right = insert(root.right,x)
    return root

def preorder(root):
    if root is None:
        return
    stack = []
    stack.append(root)
    while(len(stack)>0):
        node = stack.pop()
        print(node.data,end = " ")
        if node.right is not None:
            stack.append(node.right)
        if node.left is not None:
            stack.append(node.left)

def peek(stack): 
    if len(stack) > 0: 
        return stack[-1] 
    return None


def postorder(root):
    if root is None:
        return
    stack = []
    while True:
        while (root):
            if root.right is not None:
                stack.append(root.right)
            stack.append(root)
            root = root.left
        root = stack.pop()
        if(root.right is not None and peek(stack) == root.right):
            stack.pop()
            stack.append(root)
            root = root.right
        else:
            temp = root
            print(temp.data,end =" ")
            root = None
        if len(stack) <= 0:
            break


def inorder(root):
    if root is None:
        return
    stack = []
    temp = root
    while True:
        if temp is not None:
            stack.append(temp)
            temp = temp.left
        elif(stack):
            temp = stack.pop()
            print(temp.data,end = " ")
            temp = temp.right
        else:
            break


if __name__ == '__main__':
    print("Enter DATA in Binary search tree")
    l = list(map(int,input().split()))
    root = None 
    for t in l:
        root = insert(root,t)
    preorder(root)
    print("")
    postorder(root)
    print("")
    inorder(root)