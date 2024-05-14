class Solution {
public:
    Node* copyRandomList(Node* head) {
       
        
        if (!head) return nullptr;
        
        // Step 1: Duplicate each node and place it in between its original and next node
        Node* curr = head;
        while (curr != NULL) {
            Node* duplicate = new Node(curr->val);
            duplicate->next = curr->next;
            curr->next = duplicate;
            curr = curr->next->next;
        }
        
        // Step 2: Set random pointers for the duplicate nodes
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        // Step 3: Separate the original and duplicate lists
        Node* original = head;
        Node* duplicate = head->next;
        Node* newHead = duplicate; // Store the head of the duplicate list
        
        while (original != NULL) {
            original->next = original->next->next;
            if (duplicate->next != NULL) {
                duplicate->next = duplicate->next->next;
            }
            original = original->next;
            duplicate = duplicate->next;
        }
        
        return newHead;
    }
};
