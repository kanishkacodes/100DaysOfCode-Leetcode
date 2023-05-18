class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* leftNode = getKthNode(head, k);
        ListNode* rightNode = getKthNodeFromEnd(head, k);
        
        swap(leftNode->val, rightNode->val);
        
        return head;
    }
    
private:
    ListNode* getKthNode(ListNode* head, int k) {
        ListNode* currentNode = head;
        int count = 1;
        
        while (count < k) {
            currentNode = currentNode->next;
            count++;
        }
        
        return currentNode;
    }
    
    ListNode* getKthNodeFromEnd(ListNode* head, int k) {
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        
        for (int i = 0; i < k; i++) {
            fastPtr = fastPtr->next;
        }
        
        while (fastPtr != nullptr) {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        
        return slowPtr;
    }
};
