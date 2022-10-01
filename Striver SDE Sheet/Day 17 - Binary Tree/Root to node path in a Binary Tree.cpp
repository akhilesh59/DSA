bool getPath(TreeNode* node, int& key, vector<int>& ans) {
    if(node == NULL) return false;

    ans.push_back(node->val);
    if(node->val == key) return true;

    if(getPath(node->left, key, ans) || getPath(node->right, key, ans)) return true;

    ans.pop_back();

    return false;
}

vector<int> Solution::solve(TreeNode* root, int B) {
    vector<int> ans;

    if(root == NULL) return ans;

    getPath(root, B, ans);
}
