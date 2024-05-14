class Solution {
public:
    
    // find the length
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
        
        // decleare two pointers 
        ListNode *curr1 = headA;
        ListNode *curr2 = headB;
        
        int lengthA = lengthofll(headA);
        int lengthB = lengthofll(headB);
        int diff;
        
        //put the pointers in parallel 

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
        
        
        // check the intersection point
        
        while (curr1 != NULL && curr2 != NULL){
            if (curr1 == curr2){ 
                return curr1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        return NULL;
    }
};
