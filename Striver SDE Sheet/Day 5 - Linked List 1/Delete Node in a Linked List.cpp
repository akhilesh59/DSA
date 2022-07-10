/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Do Upvote if it Helped :)

class Solution {
public:
    void deleteNode(ListNode* node) {
        /* Since it is given that "node" is not the tail, hence we will always have a node after this.
        So what we can do is that we can swap/copy the values of the current node and the node next to it.
        Now our current node will contain the value which is to be there and the next node will contain the value which is to be deleted.
        Finally, point the current node to the next of the next node, and this will delete the undesired node.
        
        Time Complexity: O(1)

        Reason: It is a two-step process that can be obtained in constant time.

        Space Complexity: O(1)
        */
        node->val = node->next->val; // copied the value of next node to the current.
        node->next = node->next->next;
    }
};