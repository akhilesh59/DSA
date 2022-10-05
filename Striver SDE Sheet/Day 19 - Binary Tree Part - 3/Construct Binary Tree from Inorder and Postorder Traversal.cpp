class Solution {
private:
    
    TreeNode* constructTree(vector<int>& post, int postStart, int postEnd, int inoStart, int inoEnd, unordered_map<int,int>& mp) {
        
        if(postStart > postEnd || inoStart > inoEnd) return NULL;
        
        TreeNode* root = new TreeNode(post[postEnd]);
        
        int inoRoot = mp[post[postEnd]];
        int leftSubTreeSize = inoRoot-inoStart;
        
        root->left = constructTree(post, postStart, postStart+leftSubTreeSize-1, inoStart, inoRoot-1, mp);
        
        root->right = constructTree(post, postStart+leftSubTreeSize, postEnd-1, inoRoot+1, inoEnd, mp);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); ++i) mp[inorder[i]] = i;
        
        return constructTree(postorder, 0, postorder.size()-1, 0, inorder.size()-1, mp);
    }
};