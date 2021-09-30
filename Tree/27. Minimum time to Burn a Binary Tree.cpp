class Solution {
    Node* start;
    private: 
    void track_parent(Node* root, unordered_map<Node*, Node*> &parent_map, int target) {
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            if(curr->data == target) start = curr;
            
            if(curr->left) {
                parent_map[curr->left] = curr;
                q.push(curr->left);
            }
            
            if(curr->right) {
                parent_map[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> parent_map;
        
        track_parent(root, parent_map, target);
        int t = 0;
        unordered_map<Node*, bool> visited;
        
        queue<Node*> q;
        q.push(start);
        
        while(!q.empty()) {
            
            bool check = 0; // this will check that the current node will burn any other node or not
            //, and if it didn't burn any other node then we need not to increment the timer.
            
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                Node* curr = q.front(); 
                q.pop();
                
                if(curr->left && visited[curr->left] == false) {
                    check = 1;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                
                if(curr->right && visited[curr->right] == false) {
                    check = 1;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                
                if(parent_map[curr] != NULL && visited[parent_map[curr]] == false) {
                    check = 1;
                    visited[parent_map[curr]] = true;
                    q.push(parent_map[curr]);
                }
            }
            
            if(check) t++;
            
        }
        
        return t;
    }
};