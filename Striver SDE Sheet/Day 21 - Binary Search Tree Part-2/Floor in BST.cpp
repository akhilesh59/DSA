#include <bits/stdc++.h> 
#define Node TreeNode<int>
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
    int res = -1;
    while(root) {
        if(root->val > X) {
            root = root->left;
        }
        else {
            res = root->val;
            root = root->right;
        }
    }
    return res;
}