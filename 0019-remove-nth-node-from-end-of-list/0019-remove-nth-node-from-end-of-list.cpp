class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer n+1 steps ahead to maintain the gap
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove the nth node from the end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        // Get the new head node
        ListNode* newHead = dummy->next;
        delete dummy;  // Free the dummy node
        return newHead;
    }
};
