class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool flag = 1; // flag will tell us to reverse the level order traversal at alternate levels to maintain the zig-zag structure
        
        while(!q.empty()) {
            int q_size = q.size();
            vector<int> tmp(q_size);
            
            for(int i=0; i<q_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                //find the positions to fill the tmp vector with node->val
                int idx = (flag == 1) ? i : (q_size - 1 - i);
                
                tmp[idx] = node->val;
                
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }          
                        
            ans.push_back(tmp);
            flag = !flag;
        }
        
        return ans;
        
    }
};