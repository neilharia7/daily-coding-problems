"""
This problem was asked by Google.

Given the root to a binary tree, 
implement serialize(root), which serializes the tree into a string, and 
deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
"""


import json


class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
    def __repr__(self):
        return str(self.val)


def serialize(root):
    tree_map = {}
    
    if not root:
        return None
    
    serialize_left = serialize(root.left)
    serialize_right = serialize(root.right)
    
    tree_map['val'] = root.val
    if serialize_left:
        tree_map['left'] = serialize_left
    
    if serialize_right:
        tree_map['right'] = serialize_right
    
    return json.dumps(tree_map)


def deserialize(string):
    tree_map = json.loads(string)
    
    root = Node(tree_map['val'])
    
    if tree_map.get('left'):
        root.left = deserialize(tree_map['left'])
    
    if tree_map.get('right'):
        root.right = deserialize(tree_map['right'])
    
    return root


if __name__ == "__main__":
    node = Node('root', Node('left', Node('left.left')), Node('right'))
    assert deserialize(serialize(node)).left.left.val == 'left.left'
