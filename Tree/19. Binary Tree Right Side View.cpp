/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void traverse(TreeNode* node, int level, vector<int>& ans) {
        if(node == NULL) {
            return;
        }
        
        if(level == ans.size()) {
            ans.push_back(node->val);
        }
        
        if(node->right != NULL) {
            traverse(node->right, level+1, ans);
        }
        if(node->left != NULL) {
            traverse(node->left, level+1, ans);
        }
        
        return;
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<int> q;
        
        traverse(root, 0, ans);
        
        return ans;
    }
};