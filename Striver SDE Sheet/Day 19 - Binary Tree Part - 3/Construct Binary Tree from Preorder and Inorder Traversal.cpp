class Solution {
private:
    TreeNode* constructTree(vector<int>& pre, int preStart, int preEnd, vector<int>& ino, int inoStart, int inoEnd, unordered_map<int,int>& mp) {
        
        if(preStart > preEnd || inoStart > inoEnd) return NULL;
        
        TreeNode* root = new TreeNode(pre[preStart]);
        
        int inoRoot = mp[pre[preStart]];
        int leftSubTreeSize = inoRoot - inoStart;
        
        root->left = constructTree(pre, preStart+1, preStart + leftSubTreeSize, ino, inoStart, inoRoot-1, mp);
        
        root->right = constructTree(pre, preStart + leftSubTreeSize + 1, preEnd, ino, inoRoot+1, inoEnd, mp);
        
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& ino) {
        unordered_map<int,int> mp;
        for(int i=0; i<ino.size(); ++i) mp[ino[i]] = i;
        
        return constructTree(pre, 0, pre.size()-1, ino, 0, ino.size()-1, mp);
    }
};