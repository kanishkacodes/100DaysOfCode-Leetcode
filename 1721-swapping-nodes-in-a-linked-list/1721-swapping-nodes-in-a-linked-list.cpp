class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* leftNode = findKthNode(head, k);
        ListNode* rightNode = findKthNodeFromEnd(head, k);

        swap(leftNode->val, rightNode->val);

        return head;
    }

private:
    ListNode* findKthNode(ListNode* head, int k) {
        ListNode* currentNode = head;
        for (int i = 1; i < k; i++) {
            currentNode = currentNode->next;
        }
        return currentNode;
    }

    ListNode* findKthNodeFromEnd(ListNode* head, int k) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        for (int i = 0; i < k; i++) {
            fastPtr = fastPtr->next;
        }

        while (fastPtr != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        return slowPtr;
    }
};
