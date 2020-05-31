"""
This problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
"""

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        
    def __repr__(self):
        return str(self.val)
        
        
def univalCount(root):
    current_count = 0
    
    if not root:
        return 0
        
    if not root.left and not root.right:
        return 1
        
    if not root.left and root.right.val == root.val:
        return  univalCount(root.right) + 1
    
    if not root.right and root.left.val == root.val:
        return univalCount(root.left) + 1
        
    childs = univalCount(root.left) + univalCount(root.right)
    if root.val == root.left.val == root.right.val:
        current_count = 1
        
    return current_count + childs
    
    
if __name__ == "__main__":
    n = Node('0')
    n.left = Node('1')
    n.right = Node('0')
    n.right.left = Node('1')
    n.right.right = Node('0')
    n.right.left.left = Node('1')
    n.right.left.right = Node('1')
    
    print(univalCount(n))
    
