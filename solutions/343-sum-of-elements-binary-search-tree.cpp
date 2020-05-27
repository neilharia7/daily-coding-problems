/*

This problem was asked by Google.

Given a binary search tree and a range [a, b] (inclusive), 
return the sum of the elements of the binary search tree within the range.

For example, given the following tree:

    5
   / \
  3   8
 / \ / \
2  4 6  10

and the range [4, 9], return 23 (5 + 4 + 6 + 8).
*/


#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
};

node *newNode(int val) {
    node *root = new node;
    root->val = val;
    root->left = root->right = NULL;
    return root;
}

node *insert(node* node, int val) {
    if (node == NULL) {
        return newNode(val);
    }
    
    if(node->val < val) {
        node->left=insert(node->left,val);
    } else {
        node->right=insert(node->right,val);
    }
    return node;
}

void traverseInOrder(node* root, std::vector<int>& v) {
    if (root == NULL)
        return;

    traverseInOrder(root->left, v);
    // std::cout << root->val << std::endl;
    v.push_back(root->val);
    traverseInOrder(root->right, v);
}

int main () {
    
    int minRangeVal = 4, maxRangeVal = 9, total = 0;
    std::vector<int> v;

    node* root = newNode(5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 10);

    traverseInOrder(root, v);

    for(int i = 0; i < v.size(); ++i) {
        if (v[i] >= minRangeVal && v[i] <= maxRangeVal) {
            total += v[i];
        }
    }

    std::cout << total << std::endl;
    return 0;
}
