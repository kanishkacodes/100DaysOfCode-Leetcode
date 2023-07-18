class LRUCache {
public:
    class node{
        public:
            int key,val;
            node* next;
            node* prev;
            node(int newkey,int newval){
                key=newkey,val=newval;
            }
    };

    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);

    int storecap; //to store the capacity which is allowed 
    unordered_map<int,node*> mp;

    LRUCache(int capacity) {
        storecap=capacity;
        head->next=tail;
        tail->prev=head; // initialised everything first
    }
    
    void addnode(node* newnode){
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }

    void deletenode(node* delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }

    int get(int keyfind) {
        if(mp.find(keyfind)!=mp.end()){
            node* resnode=mp[keyfind];
            int result=resnode->val;
            mp.erase(keyfind);
            deletenode(resnode);
            addnode(resnode);
            mp[keyfind]=head->next; //new address
            return result;
        }
        return -1;
    }
    
    void put(int keytoput, int value) {
        if(mp.find(keytoput)!=mp.end()){ //if found in map
            node* existnode=mp[keytoput]; //then delete this from mp and list
            mp.erase(keytoput);
            deletenode(existnode); // and we will add it the right position
        }
        if(mp.size()==storecap){ //if the capacity is full
            mp.erase(tail->prev->key); //then delete the least recently used
            deletenode(tail->prev); //from map as well as list
        }
        node* nodetoput=new node(keytoput,value);
        addnode(nodetoput); //insert the node right after head as it is recently used
        mp[keytoput]=head->next;//add it to the map also
    }
};