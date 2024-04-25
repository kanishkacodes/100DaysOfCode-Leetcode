class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *fast = head;
        ListNode *slow = head;

        for (int i = 0; i < n; i++) 
            fast = fast->next;
        
        
// Move both fast and slow pointers simultaneously until the fast pointer reaches the last node.
// At this point, the slow pointer will be pointing to the node just before the one to be removed.  
        
        
        if (fast == NULL)  
            return head->next;
        
        
        
        while (fast->next != NULL) {
            fast = fast->next; 
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};
