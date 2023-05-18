class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left_ptr = head, *right_ptr = head;
        int i = 0;
        
        // Change for loop to while loop
        while (i < k - 1) {
            right_ptr = right_ptr->next;
            i++;
        }
        
        ListNode *end_ptr = right_ptr;
        
        // Change for loop to while loop
        while (right_ptr->next) {
            left_ptr = left_ptr->next;
            right_ptr = right_ptr->next;
        }
        
        swap(end_ptr->val, left_ptr->val);
        
        return head;
    }
};
