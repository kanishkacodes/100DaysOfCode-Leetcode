/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head; // Initialize slow with head
        ListNode* fast = head; // Initialize fast with head
        
        while (fast != nullptr && fast->next != nullptr){
            
            // Move slow pointer by one step
            slow = slow->next;
            // Move fast pointer by two steps
            fast = fast->next->next;
            
            // Check if slow and fast pointers meet
            if (slow == fast){
                // Cycle detected
                
                slow = head; // Reset slow to head
                
                while (slow != fast) {
                    
                    slow = slow->next;
                    fast = fast->next;
                }
                
                return slow; // Return the node where cycle starts
            }
        }
        
        return nullptr; // No cycle found
    }
};
