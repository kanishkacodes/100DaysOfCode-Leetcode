class Solution {
public:
    
    int length(ListNode * head){
        
        int len = 0;
        ListNode *curr = head;
        while (curr !=NULL){
            
            len++;
            curr = curr->next;
        }
        
        return len;
        
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        
        int len1 = length(headA);
        int len2 = length(headB);
        int diff;
        
        if (len1>len2){
            
            diff = len1-len2;
            
            while (diff != 0){
                curr1 = curr1->next;
                diff--;
            }
        }
        
        else {
            
            diff = len2-len1;
            
            while (diff != 0){
                curr2 = curr2->next;
                diff--;
            }
        }
        
        while ( curr1 != NULL && curr2 != NULL){
            
             if (curr1 == curr2){
                return curr1;
            }
            
            curr1 = curr1->next;
            curr2 = curr2->next;
            
           
            
        }
        
        return NULL;
        
        
        
    }
};