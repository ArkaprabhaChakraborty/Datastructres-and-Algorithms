class Node: 
     
    # Constructor to create a new node 
    def __init__(self, data): 
        self.data = data 
        self.left = None
        self.right = None


def peek(stack):
    if len(stack) > 0:
        return stack[-1]

def postorder(root):
    current = root
    stack = []
    while(True):
        while(current):
            if current.right != None:
                stack.append(current.right)
            stack.append(current)
            current = current.left
        if(current == None):
            current = stack.pop()
            if (current.right == None or current.right != peek(stack)):
                print(current.data)
                current = None
            elif(current.right == peek(stack)):
                temp = stack.pop()
                stack.append(current)
                current = temp
        if(len(stack)==0):
            break

root = Node(1) 
root.left = Node(2) 
root.right = Node(3) 
root.left.left = Node(4) 
root.left.right = Node(5) 
root.right.left = Node(6) 
root.right.right = Node(7) 

postorder(root)