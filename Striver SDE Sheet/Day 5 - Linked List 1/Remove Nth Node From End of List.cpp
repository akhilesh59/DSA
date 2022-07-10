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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode *fast = head, *slow = head;
        
        for(int i=0; i<n; i++) fast = fast->next; // it is given that n <= list_size
        
        if(!fast) return head->next; // it means that nth node from end will be the first node of the Given List
        
        while(fast->next) slow = slow->next, fast = fast->next;
        // Here in the above code what I have done is that, Initially i have placed the fast pointer n steps ahead of the slow pointer. 
        //This is done so that when the fast pointer reaches the end of the list then the slow pointer will be located
        // exactly before the nth node from the back to maintain the gap of n nodes that we had created initially.
        // Now remove the nth node from the back:
        slow->next = slow->next->next;
        
        return head;
    }
};