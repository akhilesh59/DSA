class CustomNode{
public:
    int sum, maxi, mini;

    CustomNode(int maxi, int mini, int sum) {
        this->maxi = maxi;
        this->mini = mini;
        this->sum = sum;
    }
};

class Solution {
private:
    
    CustomNode* recur(TreeNode* root, int& maxSum) {
        if(!root) return new CustomNode(INT_MIN, INT_MAX, 0);
        
        CustomNode* left = recur(root->left, maxSum);
        CustomNode* right = recur(root->right, maxSum);
        
        int curr = root->val;
        
        if(curr > left->maxi && curr < right->mini) {
            maxSum = max(curr + right->sum + left->sum, maxSum);
            
            return (new CustomNode(max(curr, right->maxi), min(curr, left->mini), (curr + right->sum + left->sum)));
        }
        else {
            return (new CustomNode(INT_MAX, INT_MIN, INT_MIN));
        }
    }
    
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        CustomNode* res = recur(root, maxSum);
        return maxSum;
    }
};