#include <bits/stdc++.h> 

#define Node TreeNode<int>
#define val data

void changeTree(BinaryTreeNode < int > * root) {
    if(!root) return;
    
    int left = 0, right = 0;
    if(root->left) left = root->left->val;
    if(root->right) right = root->right->val;
    
    if(root->val > (left+right)) {
        if(root->left) root->left->val = root->val;
        else if(root->right) root->right->val = root->val;
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    left = 0; right = 0;
    if(root->left) left = root->left->val;
    if(root->right) right = root->right->val;
    
    if(root->left || root->right) root->val = left+right;
}  