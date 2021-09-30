/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.

void recursive(Node* node, int level, vector<int>& ans) {
    if(node == NULL) return;
    
    if(level == ans.size()) ans.push_back(node->data);
    
    recursive(node->left, level+1, ans);
    recursive(node->right, level+1, ans);
}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   
   recursive(root, 0, ans);
   
   return ans;
}
