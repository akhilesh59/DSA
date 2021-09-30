class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        vector<int> ans;
        
        while(!q.empty()) {
            auto tmp = q.front();
            q.pop();
            
            Node* node = tmp.first;
            int line = tmp.second;
            
            if(!mp[line]) {
                mp[line] = node->data;
            }
            
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
