#include <bits/stdc++.h> 
#define Node BinaryTreeNode<int> 

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    if(!root) return {{}, {}, {}};
    vector<vector<int>> ans;
    vector<int> pre, in, post;
    
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    
    while(!st.empty()) {
        auto it = st.top(); st.pop();
        Node* node = it.first;
        int lvl = it.second;
        
        if(lvl == 1) {
            pre.push_back(node->data);      
            st.push({node, 2});
            if(node->left) st.push({node->left, 1});
        }
        else if(lvl == 2) {
            in.push_back(node->data);
            st.push({node, 3});
            if(node->right) st.push({node->right, 1});           
        }
        else if(lvl == 3) {
            post.push_back(node->data);
        }       
    }
    
    ans.push_back(in); ans.push_back(pre); ans.push_back(post);
    
    return ans;
    
}