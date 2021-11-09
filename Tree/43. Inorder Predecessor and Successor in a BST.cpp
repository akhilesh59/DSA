/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively

Node* findsucc(Node* root, int key) {
    Node* succ = NULL;
    
    while(root != NULL) {
        if(key >= root->key) {
            root = root->right;
        }
        else {
            succ = root;
            root = root->left;
        }
    }
    
    return succ;
}

Node* findpred(Node* root, int key) {
    Node* pred = NULL;
    
    while(root != NULL) {
        if(key <= root->key) {
            root = root->left;
        }
        else {
            pred = root;
            root = root->right;
        }
    }
    
    return pred;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    if(root == NULL) return;
    Node* succ = findsucc(root,key);
    Node* pred = findpred(root,key);
    
    pre = pred;
    suc = succ;
    
    // cout<<succ<<' '<<pred<<'\n';

}