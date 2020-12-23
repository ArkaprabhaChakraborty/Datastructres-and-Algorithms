#simple tree node
class Node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.data = key

def insert(root,c):
    if root is None: 
        return Node(c)
    #here is a special case of binary tree known as binary search tree 
    elif c < root.data:
        root.left = insert(root.left,c)
    else:
        root.right = insert(root.right,c)
    return root

def inorder(root):
    if root != None:
        inorder(root.left)
        print("%d "%(root.data))
        inorder(root.right)

def minval(root):
    while root.left != None:
        root = root.left
    return root

def delete(root,x):
    #base case
    if root == None:
        return root
    #if x is greater than the current root.data recur down the right subtree
    if x > root.data:
        root.right = delete(root.right,x)
    #else if x is less than the current root.data recur down the left subtree
    elif x < root.data:
        root.left = delete(root.left,x)
    #else if x == root.data then this is the node to be deleted 
    else:
        # if it is a node with one child
        # replace its value with that of its successor
        if root.right is None:
            temp = root.left
            root = None
            return temp
        elif root.left is None:
            temp = root.right
            root = None
            return temp
        #else get the minimum value from the right subtree i.e the inorder successor
        temp = minval(root.right)
        #replace the current data with its inorder successor 
        root.data = temp.data
        #delete the inorder successor
        root.right = delete(root.right,temp.data)
    return root

# main driver code
if __name__ == '__main__':
    print("Enter elements in Binary Search Tree")
    s = list(map(int,input().split()))
    r = None
    for i in s:
        r = insert(r,i)
    print("Inorder Traversal:")
    inorder(r)
    x = int(input())
    delete(r,x)
