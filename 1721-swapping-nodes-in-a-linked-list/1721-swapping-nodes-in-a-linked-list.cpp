class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);  // Create a dummy node
        dummy->next = head;
        
        ListNode* firstNode = dummy;
        ListNode* secondNode = dummy;
        
        // Move firstNode to the kth node from the beginning
        for (int i = 0; i < k; i++) {
            firstNode = firstNode->next;
        }
        
        ListNode* temp = firstNode;
        
        // Move secondNode to the kth node from the end
        while (temp) {
            temp = temp->next;
            secondNode = secondNode->next;
        }
        
        // Swap the values of firstNode and secondNode
        swap(firstNode->val, secondNode->val);
        
        return dummy->next;  // Return the modified list
    }
};
