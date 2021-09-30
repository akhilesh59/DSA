/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    int ans = -1;
    while(root) {
        if(X == root->val) return root->val;
        else if(X > root->val) {
            ans = root->val;
            root = root->right;
        }
        else root = root->left;
    }
    return ans;
}