/*
This problem was asked by Uber.

Given a binary tree and an integer k, return whether there exists a root-to-leaf path that sums up to k.

For example, given k = 18 and the following binary tree:

    8
   / \
  4   13
 / \   \
2   6   19
Return True since the path 8 -> 4 -> 6 sums to 18.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *create(int val) {
    struct TreeNode *node =  (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* node, int val) {
    if (node == NULL) {
        return create(val);
    }
    
    if (node->val > val) {
        node->left = insert(node->left, val);
    } else {
        node->right = insert(node->right, val);
    }
    
    return node;
}

bool pathSum(struct TreeNode* node, int k) {
    if (node == NULL)
        return k == 0;
    
    bool result = 0;
    int s = k - node->val;
    
    if (s == 0 && node->left == NULL && node->right == NULL)
        return true;
    if (node->left != NULL)
        result = result || pathSum(node->left, s);
    if (node->right != NULL)
        result = result || pathSum(node->right, s);
        
    return result;
}

int main() {
    struct TreeNode *root = NULL;
    root = insert(root, 8);
    insert(root, 4);
    insert(root, 13);
    insert(root, 2);
    insert(root, 6);
    insert(root, 19);
    
    int k = 18;
    
    std::cout << pathSum(root, k) << std::endl;
    return 0;
}
