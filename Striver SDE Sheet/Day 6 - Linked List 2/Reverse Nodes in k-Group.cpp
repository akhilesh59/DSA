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

/*

Approach:

The following steps are needed to arrive at the desired output. 

    1. Create a dummy node. Point next to this node to head of the linked list provided.
    2. Iterate through the given linked list to get the length of the list.
    3. Create three pointer pre,cur and nex to reverse each group. Why? If we observe output, we can see that we have to reverse each group, apart from modifying links of group.
    4. Iterate through the linked list until the length of list to be processed is greater than and equal to given k.
    5. For each iteration, point cur to pre->next and nex to nex->next.
    6. Start nested iteration for length of k.
    7. For each iteration, modify links as following steps:-

    cur->next = nex->next
    nex->next = pre->next
    pre->next = nex
    nex = cur->next
    Move pre to cur and reduce length by k.

*/

class Solution {
private:
    int getLength(ListNode* head) {
        int cnt = 0;
        while(head) {
            head = head->next;
            ++cnt;
        }
        return cnt;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr;
        ListNode* nex;
        
        int len = getLength(head);
        
        while(len >= k) {
            curr = prev->next;
            nex = curr->next;
            
            for(int i=1; i<k; ++i) {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            
            prev = curr;
            len -= k;
        }
        
        return dummy->next;
        
    }
};