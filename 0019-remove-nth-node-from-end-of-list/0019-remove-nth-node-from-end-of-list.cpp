// slow fast
class Solution {
public:
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr; // Initialize previous pointer

    // Move fast pointer by n steps
    for(int i = 0 ; i < n ; i++) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != nullptr) {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }

    // If prev is nullptr, it means we're removing the first node
    if (prev == nullptr) {
        return head->next;
    } else {
        // Skip the nth node by adjusting the pointers
        prev->next = slow->next;
        return head;
    }
}


};