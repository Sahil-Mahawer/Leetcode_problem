// Brute Force

// class LRUCache {
// public:

// vector<pair<int,int>> cache;
// int n;
//     LRUCache(int capacity) {
//         n = capacity;
//     }
    
//     int get(int key) {
        
//         for(int i=0;i<cache.size();i++){

//             if(cache[i].first == key){
//                 int value = cache[i].second;

//                 pair<int,int> temp = cache[i];

//                 cache.erase(cache.begin() + i); // remove from that position  

//                 cache.push_back(temp);  // store it at the back as it is most recently used

//                 return value;
//             }

//         }
        
//         return -1;
//     }
    
//     void put(int key, int value) {

//         for(int i=0;i<cache.size();i++){

//             if(cache[i].first == key){

//                 cache.erase(cache.begin() + i);

//                 cache.push_back({key,value});

//                 return;
//             }
//         }

//         if(cache.size() == n){

//             cache.erase(cache.begin());

//             cache.push_back({key, value});
//         }

//         else{

//             cache.push_back({key, value});

//         }

        
        
//     }
// };


class LRUCache {
public:

// head->next = Most Recenlt used
// tail -> prev = Least Recently used  

// Here we have used Doubly Linked List

class Node{
    public:

    int key, value;
    Node *prev, *next;

    Node(int k, int v){

        key = k;
        value = v;
        prev = NULL;
        next = NULL;

    }

};



int limit;

unordered_map<int, Node*> mp;

void delNode(Node * Node_To_delete){

    Node *prevOf_Node_toBe_deleted =  Node_To_delete->prev;
    Node* nextOf__Node_toBe_deleted = Node_To_delete->next;

    prevOf_Node_toBe_deleted -> next = nextOf__Node_toBe_deleted;

    nextOf__Node_toBe_deleted -> prev = prevOf_Node_toBe_deleted;

    
}

void addNode(Node *newNode){

    Node * nextOf_newNode = head->next;

    head->next = newNode;
    newNode->prev = head;

    newNode -> next = nextOf_newNode;
    nextOf_newNode->prev = newNode;

}

Node *head = new Node(-1, -1);
Node *tail = new Node(-1, -1);

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end()){  // key not exist
                return -1;
        }

        Node *ansNode = mp[key];
        int ans = ansNode->value;

        mp.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        mp[key] = ansNode;


        return ans;

    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){

            Node *Node_To_delete = mp[key]; // node to be deleted
            delNode(Node_To_delete);
            mp.erase(key);

        }

        if(mp.size() == limit){  // if we reach to the limit now we delete the most least used cache 

            mp.erase(tail->prev->key);
            delNode(tail->prev);

        }

        Node *newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */