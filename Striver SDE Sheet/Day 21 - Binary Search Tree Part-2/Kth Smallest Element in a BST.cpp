class Solution {
private:
    void inorder(TreeNode* root, int& k, int& cnt, int& res) {
        if(!root) return;
        
        inorder(root->left, k, cnt, res);
        ++cnt;
        if(cnt == k) {
            res = root->val;
            return;
        }
        inorder(root->right,k, cnt, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, res = -1;
        inorder(root, k, cnt, res);
        return res;
    }
};