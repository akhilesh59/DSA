class helperNode {
    public :
    int maxi, mini, node_cnt;
    
    helperNode(int maxi, int mini, int node_cnt) {
        this->maxi = maxi;
        this->mini = mini;
        this->node_cnt = node_cnt;
    }
};

class Solution{
    private:
    helperNode largestBstSubtreeHelper(Node* root) {
        if(root == NULL) return helperNode(INT_MIN, INT_MAX, 0);
        
        // get the values from the left and right subtree from the current node:
        
        helperNode left = largestBstSubtreeHelper(root->left);
        helperNode right = largestBstSubtreeHelper(root->right);
        
        // If current node is Greater than the Max node of left AND smaller than
        // the Min node of the right subtree then it is a Valid BST
        if(root->data > left.maxi && root->data < right.mini) {
            
            return helperNode(max(root->data, right.maxi), min(root->data, left.mini), (1 + left.node_cnt + right.node_cnt));
            
        }
        // otherwise it will not be BST, hence return the values which ill not be comparabale further
        else {
            return helperNode(INT_MAX, INT_MIN, max(left.node_cnt, right.node_cnt));
        }
        
    }
    
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return largestBstSubtreeHelper(root).node_cnt;
    }
};