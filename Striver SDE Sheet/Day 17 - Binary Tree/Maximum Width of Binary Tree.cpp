
class Solution {
    #define ll long long
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        ll ans = INT_MIN;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()) {
            ll sz = q.size();
            ll min_id = q.front().second;
            ll first,last;
            
            for(int i=0; i<sz; i++) {
                TreeNode* curr = q.front().first;
                ll id = q.front().second - min_id;
                q.pop();
                
                if(i == 0) first = id;
                if(i == sz-1) last = id;
                
                if(curr->left) q.push({curr->left, id*2+1});
                if(curr->right) q.push({curr->right, id*2+2});
            }
            
            ans = max(ans, (last-first)+1);
        }
        
        return ans;
        
    }
};