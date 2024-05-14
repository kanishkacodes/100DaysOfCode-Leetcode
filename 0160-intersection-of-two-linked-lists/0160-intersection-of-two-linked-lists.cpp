class Solution {
public:
    int lengthofll(ListNode *head){
        int len = 0;
        ListNode *curr = head;
        while (curr != NULL){
            len++;
            curr = curr->next;
        }
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curr1 = headA;
        ListNode *curr2 = headB;
        
        int lengthA = lengthofll(headA);
        int lengthB = lengthofll(headB);
        int diff;

        if (lengthA > lengthB){
            diff =  lengthA - lengthB;
            while (diff != 0){
                curr1 = curr1->next;
                diff--;
            }
        }
        else{
            diff = lengthB - lengthA;
            while (diff != 0){
                curr2 = curr2->next;
                diff--;
            }
        }
        
        // Check for intersection
        while (curr1 != NULL && curr2 != NULL){
            if (curr1 == curr2){ // Compare the nodes, not just the values
                return curr1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        return NULL;
    }
};
