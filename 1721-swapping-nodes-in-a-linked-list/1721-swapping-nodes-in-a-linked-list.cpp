class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *leftNode = head, *rightNode = head;
        
        // Traverse to the kth node from the beginning
        for (int i = 0; i < k - 1; i++) {
            rightNode = rightNode->next;
        }
        
        ListNode *endNode = rightNode;
        
        // Traverse to the end of the list while updating leftNode
        while (rightNode->next) {
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }
        
        // Swap the values of endNode and leftNode
        swap(endNode->val, leftNode->val);
        
        return head;
    }
};
