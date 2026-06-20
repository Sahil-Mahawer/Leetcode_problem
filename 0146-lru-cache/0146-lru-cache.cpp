class LRUCache {
public:

class Node{
public:
int key, val;
Node *next, *prev;

Node(int k, int v){
    key = k;
    val = v;
    next = NULL;
    prev = NULL;

}
};

    int limit;
    unordered_map<int,Node*>mp;

    void delNode(Node *Node_to_delete){

        Node* prevOf_Node_to_delete  = Node_to_delete -> prev;
        Node* nextOf_Node_to_delete = Node_to_delete -> next;

        prevOf_Node_to_delete ->next = nextOf_Node_to_delete;
        nextOf_Node_to_delete -> prev =  prevOf_Node_to_delete;
    }

    void add_Node_after_Head(Node *newNode){

        Node *nextOf_newNode = head->next;
        head->next = newNode;
        newNode->prev = head;

        newNode->next = nextOf_newNode;
        nextOf_newNode -> prev = newNode;
    }

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node *ansNode = mp[key];
        int ansValue = ansNode->val;

        mp.erase(key);
        delNode(ansNode);

        add_Node_after_Head(ansNode);
        mp[key] = ansNode;

        return ansValue;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){

            Node *Node_to_delete = mp[key];
            delNode(Node_to_delete);
            mp.erase(key);
        }

        if(mp.size() == limit){
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node *newNode = new Node(key, value);
        add_Node_after_Head(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */