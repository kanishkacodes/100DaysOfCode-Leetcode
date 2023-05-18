class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left_ptr = head, *right_ptr = head;
        for (int i = 0; i < k-1; i++) {
            right_ptr = right_ptr->next;
        }
        
        ListNode *end_ptr = right_ptr;
        for (; right_ptr->next; left_ptr = left_ptr->next, right_ptr = right_ptr->next) {
            // Code inside the loop remains the same
        }
        
        swap(end_ptr->val, left_ptr->val);
        
        return head;
    }
};

