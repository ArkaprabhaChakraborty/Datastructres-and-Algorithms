'''
Given Preorder, Inorder and Postorder traversals of some tree of size N. The task is to check if they are all of the same tree or not.

Example 1:

Input:
N = 5
preorder[] = {1 2 4 5 3}
inorder[] = {4 2 5 1 3}
postorder[] = {4 5 2 3 1}
Output: Yes
Explanation: 
All of the above three traversals 
are of the same tree.
           1
         /   \
        2     3
            /   \
           4     5
 

Example 2:

Input:
N = 5
preorder[] = {1 5 4 2 3}
inorder[] = {4 2 5 1 3}
postorder[] = {4 1 2 3 5}
Output: No
Explanation: The three traversals can 
not be of the same tree.

Your Task:
You don't need to read input or print anything. Complete the function checktree() which takes the preorder, inorder, postorder traversal along with integer N as input parameters and returns a boolean value denoting if the three traversals are of the same tree or not. 


Expected Time Complexity: O(Log N)
Expected Auxiliary Space: O(1)
'''

def checktree(preorder, inorder, postorder, n): 
    # Your code goes here
    if (n==0):
        return 1
    if (n==1):
        return ((preorder[0] == inorder[0]) and (inorder[0] == postorder[0]))
    if( preorder[0] != postorder[n-1] ): 
        return 0    
    idx = -1
    
    for i in range(n):
        if inorder[i]==preorder[0]:
            idx = i
            break
    if idx == -1:
        return 0
    r1 = checktree(preorder[1:],inorder,postorder,idx)  
    r2 = checktree(preorder[idx+1:],inorder[idx+1:],postorder[idx:],n-idx-1)
    return (r1 and r2)