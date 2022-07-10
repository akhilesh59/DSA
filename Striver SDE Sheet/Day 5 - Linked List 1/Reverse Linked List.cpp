/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* recursive(ListNode* head) {
        if(!head->next) return head;  // Base Case if when recursion reaches to the last node and this will be the head of the head of the required list.
        
        ListNode* rev = recursive(head->next);
        // and so we do not perform any operation on this returned head, and we just simply keep on returning it.
        head->next->next = head;
        head->next = NULL;
        
        return rev;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        
        // Iterative:
//         ListNode* dummy = NULL;
//         ListNode* nxt = head->next;
        
//         while(head->next) {
//             head->next = dummy;
//             dummy = head;
//             head = nxt;
//             nxt = nxt->next;        
//         }
        
//         head->next = dummy;
        
        // Recursive :
        return recursive(head);
        
        return head;
    }
};