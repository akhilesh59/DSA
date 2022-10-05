/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    pre = NULL, suc = NULL;
    Node* tmp = root;
    
    while(tmp) {
        if(tmp->key >= key) {
            tmp = tmp->left;
        }
        else {
            pre = tmp;
            tmp = tmp->right;
        }
    }
    
    tmp = root;
    
    while(tmp) {
        if(tmp->key <= key) {
            tmp = tmp->right;
        }
        else {
            suc = tmp;
            tmp = tmp->left;
        }
    }

}