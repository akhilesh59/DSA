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
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;
    TreeNode* prev;
    
    void inorder(TreeNode* root) {
        
        if(root == NULL) return;
        
        inorder(root->left); //Traverse left left left....
        
        if(prev != NULL && (prev->val > root->val)) {
            
            if(first == NULL) {     // If this is a fors violation, mark it the 
                first = prev;       // prev as first and curr node i.e. root as
                mid = root;         // mid
            }
            else last = root;   // If its a second violation, mark it as last
            
        }
        
        // mark the current node as prev (inorder traversal - visiting the node)
        prev = root;
        
        inorder(root->right); //Traverse right right right....
        
    }
    
public:
    void recoverTree(TreeNode* root) {
        
        first = mid = last = NULL;
        prev = new TreeNode(INT_MIN);
        
        inorder(root);
        
        if(last == NULL) {  // The case when the swapped nodes are adjacent
            swap(first->val, mid->val);
        }
        else {
            swap(first->val, last->val);
        }
        
    }
};