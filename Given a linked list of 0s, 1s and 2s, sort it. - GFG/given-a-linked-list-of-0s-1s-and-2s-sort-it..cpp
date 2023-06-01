//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
public:
    /*
        Function to sort a linked list of 0s, 1s, and 2s.
        The idea is to count the occurrences of 0s, 1s, and 2s in the linked list,
        and then update the values in the linked list based on the count.
    */
    Node* segregate(Node* head) {      
        // Segment 1: Initialize counters for each value
        int zero = 0;
        int one = 0;
        int two = 0;
        
        // Segment 2: Iterate through the linked list to count the occurrences
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == 0)
                zero++;
            else if (temp->data == 1)
                one++;
            else if (temp->data == 2)
                two++;

            temp = temp->next;
        }
        
        // Segment 4: Reset the 'temp' pointer to the beginning of the linked list
        temp = head;
        
        /*
            Segment 5: Update the values in the linked list based on the counter values
            We start from the beginning of the linked list and update the values:
            - If there are remaining '0' values, set the current node's data to 0 and decrement the counter.
            - If there are remaining '1' values, set the current node's data to 1 and decrement the counter.
            - If there are remaining '2' values, set the current node's data to 2 and decrement the counter.
            This process ensures that the linked list is sorted in non-decreasing order of values.
        */
        while (temp != NULL) {
            if (zero != 0) {
                temp->data = 0;
                zero--;
            } else if (one != 0) {
                temp->data = 1;
                one--;
            } else if (two != 0) {
                temp->data = 2;
                two--;
            }
            
            // Segment 6: Move to the next node
            temp = temp->next;
        }

        // Segment 7: Return the sorted linked list
        return head;
    }
};



//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends