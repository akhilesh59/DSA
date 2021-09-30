/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private: 
    void track_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent_map) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* curr_node = q.front();
            q.pop();
            
            if(curr_node->left != NULL) {
                parent_map[curr_node->left] = curr_node;
                q.push(curr_node->left);
            }
            if(curr_node->right != NULL) {
                parent_map[curr_node->right] = curr_node;
                q.push(curr_node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> parent_map;
        
        track_parent(root, parent_map);
        
        unordered_map<TreeNode*,bool> visited;
        
        queue<TreeNode*> q;
        q.push(target);
        
        visited[target] = true;
        
        int curr_dis = 0;
        
        while(!q.empty()) {
            
            if(curr_dis++ == k) break; // agar 1 se initialise kara hota curr_dis ko to pehle check karte ki break hoga ya nhi, phir agar break na hota to increment karte.
            
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != NULL && visited[node->left] == false) {
                    visited[node->left] = true;
                    q.push(node->left);
                }
                
                if(node->right != NULL && visited[node->right] == false) {
                    visited[node->right] = true;
                    q.push(node->right);
                }
                
                if(parent_map[node] && visited[parent_map[node]] == false) {
                    visited[parent_map[node]] = true;
                    q.push(parent_map[node]);
                }
            }
        }
        
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            ans.push_back(tmp->val);
        }
        
        
        
        return ans;
        
    }
};