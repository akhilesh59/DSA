#include <bits/stdc++.h> 
#define Node TreeNode<int>

static bool isLeaf(Node* root) {
    return (!root->left && !root->right);
}

void addLeftBoundary(Node* root, vector<int>& ans) {
    Node* curr = root->left;
    while(curr) {
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addLeafNodes(Node* root, vector<int>& ans) {
    if(isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeafNodes(root->left, ans);
    if(root->right) addLeafNodes(root->right, ans);
}

void addRightBoundary(Node* root, vector<int>& ans) {
    Node* curr = root->right;
    vector<int> tmp;
    while(curr) {
        if(!isLeaf(curr)) tmp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    
    for(int i=tmp.size()-1; i>=0; --i) {
        ans.push_back(tmp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(!root) return ans;
    
    if(!isLeaf(root)) ans.push_back(root->data);
    
    addLeftBoundary(root, ans);
    addLeafNodes(root, ans);
    addRightBoundary(root, ans);
    
    return ans;
}