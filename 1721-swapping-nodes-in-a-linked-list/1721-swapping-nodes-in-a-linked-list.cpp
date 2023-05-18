class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* leftNode = nullptr;
        ListNode* rightNode = nullptr;
        ListNode* currentNode = head;

        // Traverse the list to find the kth node from the beginning
        for (int i = 1; i < k; i++) {
            currentNode = currentNode->next;
        }
        leftNode = currentNode;

        ListNode* endNode = head;
        
        // Traverse the list to find the kth node from the end
        while (currentNode->next) {
            currentNode = currentNode->next;
            endNode = endNode->next;
        }
        rightNode = endNode;

        // Swap the values of the kth node from the beginning and end
        swap(leftNode->val, rightNode->val);

        return head;
    }
};
