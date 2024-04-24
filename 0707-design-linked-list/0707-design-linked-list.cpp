class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int val) {
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    
    MyLinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        Node* curr = head->next;
        int count = 0;
        while (curr != tail && count < index) {
            curr = curr->next;
            count++;
        }
        if (curr != tail) {
            return curr->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        Node* nextNode = head->next;
        Node* prevNode = head;

        prevNode->next = node;
        nextNode->prev = node;
        node->next = nextNode;
        node->prev = prevNode;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        Node* nextNode = tail;
        Node* prevNode = tail->prev;

        prevNode->next = node;
        nextNode->prev = node;
        node->next = nextNode;
        node->prev = prevNode;
    }
    
    void addAtIndex(int index, int val) {
        Node* cur = head->next;
        while (cur && index > 0) {
            cur = cur->next;
            index--;
        }
        if (cur && index == 0) {
            Node* node = new Node(val);
            Node* nextNode = cur;
            Node* prevNode = cur->prev;

            prevNode->next = node;
            nextNode->prev = node;
            node->next = nextNode;
            node->prev = prevNode;
        }
    }
    
    void deleteAtIndex(int index) {
        Node* cur = head->next;
        while (cur && index > 0) {
            cur = cur->next;
            index--;
        }
        if (cur && cur != tail && index == 0) {
            Node* nextNode = cur->next;
            Node* prevNode = cur->prev;

            nextNode->prev = prevNode;
            prevNode->next = nextNode;

            delete cur; // Deallocation of memory for the deleted node
        }
    }
};
