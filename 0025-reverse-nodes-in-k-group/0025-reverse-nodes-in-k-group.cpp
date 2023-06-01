/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Segment 1: Check if head is NULL or k is 1
        if (head == NULL || k == 1) {
            return head;
        }
        
        // Segment 2: Create a dummy node and set its next pointer to the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Segment 3: Initialize three pointers: cur, nex, and pre to the dummy node
        ListNode* cur = dummy; // Pointer to the current node in the group
        ListNode* nex = dummy; // Pointer to the next node in the group
        ListNode* pre = dummy; // Pointer to the previous node before the group
        int count = 0; // Counter to keep track of the number of nodes
        
        // Segment 4: Count the number of nodes in the list
        while (cur->next != NULL) {
            cur = cur->next;
            count++;
        }
        
        // Segment 5: Reverse the list in groups of k
        while (count >= k) {
            cur = pre->next; // Move cur pointer to the start of the current group
            nex = cur->next; // Move nex pointer to the next node after the current group
            
            // Segment 6: Reverse a group of k nodes
            for (int i = 0; i < k - 1; ++i) {
                cur->next = nex->next; // Reverse the link between current node and next node
                nex->next = pre->next; // Reverse the link between next node and previous group
                pre->next = nex; // Update the next pointer of the previous group to the current node
                nex = cur->next; // Move nex pointer to the next node for the next iteration
            }
            
            // Segment 7: Move pre to the last node of the reversed group
            pre = cur;
            count -= k;
        }
        
        // Segment 8: Return the next pointer of the dummy node, which is the head of the reversed list
        return dummy->next;
    }
};
