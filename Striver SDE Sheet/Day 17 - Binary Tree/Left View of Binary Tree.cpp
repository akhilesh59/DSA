void recur(Node* root, vector<int>& ans, int lvl) {
    if(!root) return;
    
    if(lvl == ans.size()) ans.push_back(root->data);
    recur(root->left, ans, lvl+1);
    recur(root->right, ans, lvl+1);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    recur(root, ans, 0);
    return ans;
}