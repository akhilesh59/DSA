class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        vector<int> ans;
        
        while(!q.empty()) {
            
            auto tmp = q.front();
            q.pop();
            
            Node* node = tmp.first;
            int line = tmp.second;
            
            mp[line] = node->data;
            
            if(node->left != NULL) {
                q.push({node->left, line-1});
            }
            
            if(node->right != NULL) {
                q.push({node->right, line+1});
            }
            
        }
        
        for(auto i : mp) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};