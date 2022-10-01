class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; ++i) {
                auto it = q.front(); q.pop();
                Node *node = it.first;
                int vertical = it.second;
                
                if(mp.find(vertical) == mp.end()) mp[vertical] = node->data;
                
                if(node->left) q.push({node->left, vertical-1});
                if(node->right) q.push({node->right, vertical+1});
            }
        }
        
        for(auto it : mp) ans.push_back(it.second);
        
        return ans;
    }
};