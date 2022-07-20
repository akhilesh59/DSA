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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;
        ListNode* curr = head;
        ListNode* tail = head;
        int len = 1;
        
        while(tail->next) {
            ++len;
            tail = tail->next;
        }
        
        k = k%len;
        if(k == 0) return head;
        
        for(int i=0; i<len-k-1; ++i) curr = curr->next;
        
        tail->next = head;
        head = curr->next;
        curr->next = NULL;
        
        return head;
    }
};