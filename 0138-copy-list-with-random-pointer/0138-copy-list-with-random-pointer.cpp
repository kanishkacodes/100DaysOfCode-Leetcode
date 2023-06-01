/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Initialize two pointers, 'iter' and 'front'
        Node *iter = head; 
        Node *front = head;

        // First round: make a copy of each node and link them together side-by-side in a single list.
        while (iter != NULL) {
            front = iter->next;

            // Create a new node with the same value as the current node
            Node *copy = new Node(iter->val);

            // Connect the new node to the original node and the next node
            iter->next = copy;
            copy->next = front;

            // Move to the next pair of nodes
            iter = front;
        }

        // Second round: assign random pointers for the copy nodes.
        iter = head;
        while (iter != NULL) {
            if (iter->random != NULL) {
                // Set the random pointer of the copied node to the corresponding copied random node
                iter->next->random = iter->random->next;
            }
            
            // Move to the next original node
            iter = iter->next->next;
        }

        // Third round: restore the original list and extract the copy list.
        iter = head;
        Node *pseudoHead = new Node(0);
        Node *copy = pseudoHead;

        while (iter != NULL) {
            front = iter->next->next;

            // Extract the copied node and connect it to the copy list
            copy->next = iter->next;

            // Restore the original list by connecting the original nodes
            iter->next = front;

            // Move to the next pair of nodes
            copy = copy->next; 
            iter = front;
        }

        // Return the copy list (excluding the pseudoHead)
        return pseudoHead->next;
    }
};
