/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        // STEP 1:
        Node *ptr = head;
        while(ptr) {
            Node* tmp = new Node(ptr->val);
            tmp->next = ptr->next;
            ptr->next = tmp;
            ptr = ptr->next->next;
        }

        // STEP 2:
        ptr = head;
        while(ptr) {
            ptr->next->random = (ptr->random) ? ptr->random->next : NULL;
            ptr = ptr->next->next;
        }

        // STEP 3:       
        Node* dummy = new Node(-1);
        ptr = dummy;
        Node* curr = head;
        Node* nxt = head;
        
        while(nxt) {
            nxt = curr->next->next;
            ptr->next = curr->next;
            ptr = ptr->next;
            curr->next = nxt;
            curr = curr->next;            
        }
        
        return dummy->next;
    }
};