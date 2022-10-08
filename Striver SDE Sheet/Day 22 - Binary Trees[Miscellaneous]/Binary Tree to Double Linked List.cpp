#include <bits/stdc++.h> 
#define Node BinaryTreeNode<int>

void recur(Node* curr, Node* &prev) {
    if(!curr) return;
    recur(curr->left, prev);
    
    curr->left = prev;
    prev->right = curr;
    prev = curr;
    
    recur(curr->right, prev);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    
    recur(root, prev);
    
    return dummy->right;
}

// Using Morris Traversal :

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    
    Node* curr = root;

    while(curr) {
        if(curr->left) {
            Node* tmp = curr->left;

            while(tmp->right && tmp != curr) {
                tmp = tmp->right;
            }

            if(tmp->right == NULL) { // create Thread
                tmp->right = curr;
                curr = curr->left;
            }
            else {
                tmp->right = NULL; // delete the thread
                // make DLL connections:
                prev->right = curr;
                curr->left = prev;
                prev = curr;
                curr = curr->right;
            }
            
        }
        else {
            prev->right = curr;
            curr->left = prev;
            prev = curr;
            curr = curr->right;
        }
    }
    
    Node* head = dummy->right;
    head->left = NULL;
    return head;
}