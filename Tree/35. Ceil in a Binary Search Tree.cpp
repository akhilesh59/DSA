class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        int ans = INT_MAX;
        
        while(root) {
            if(root->data == K) return 0;
            
            if(K > root->data) {
                ans = min(ans, abs(K-root->data));
                root = root->right;
            }
            else {
                ans = min(ans, abs(K-root->data));
                root = root->left;
            }
        }
        
        return ans;
    }
};

