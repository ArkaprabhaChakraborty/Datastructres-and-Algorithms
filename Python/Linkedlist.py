class Node:
    def __init__(self,data):
        self.data = data
        self.next = None


def insert(head,data):
    newnode = Node(data)
    newnode.next = head
    head = newnode
    return head

def printf(head):
    temp = head
    while(temp != None):
        print(temp.data,end = ' ')
        temp = temp.next   

head = None
for i in range(5):
    head = insert(head,i)
printf(head)