class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int, map<int, multiset<int>>> mp;
        
        q.push({root,{0,0}});
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; ++i) {
                auto p = q.front(); q.pop();
                TreeNode* node = p.first;
                int v_lvl = p.second.first, h_lvl = p.second.second;
                
                mp[v_lvl][h_lvl].insert(node->val);
                
                if(node->left) q.push({node->left, {v_lvl-1, h_lvl+1}});
                if(node->right) q.push({node->right, {v_lvl+1, h_lvl+1}});
            }
        }
        
        for(auto it1 : mp) {
            vector<int> tmp;
            for(auto it2 : it1.second) {
                for(auto it_set : it2.second) tmp.push_back(it_set);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};