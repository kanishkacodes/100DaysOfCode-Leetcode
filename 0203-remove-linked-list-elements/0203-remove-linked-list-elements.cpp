/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //base case, recursion ends when NULL is reached
        if (head == NULL) return NULL;

        //the node has to be removed -> it is skipped during the iteration
        if (head->val == val) return removeElements(head->next, val);

        //the node doesn't have to be skipped -> the rest of the list has 
        //to be joined to the node
        head->next = removeElements(head->next, val);
        return head;
    }
};