class Solution
{
private:

    void recur(Node* root, int& k, int& res) {
        if(!root) return;
        
        recur(root->right, k , res);
        
        --k;
        
        if(k == 0) {
            res = root->data;
            return;
        }
        
        recur(root->left, k ,res);
        
    }

public:
    int kthLargest(Node *root, int k)
    {
        int res = -1;
        recur(root, k, res);
        return res;
    }
};