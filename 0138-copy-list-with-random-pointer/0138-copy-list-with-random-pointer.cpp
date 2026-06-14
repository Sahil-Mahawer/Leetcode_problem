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

Node *find(Node *curr1, Node *curr2, Node *x){

    if(x == NULL){
        return NULL;
    }

    while(curr1 != x){
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return curr2;
}
    Node* copyRandomList(Node* head) {
        
        Node* HeadCopy = new Node(0);
        Node *TailCopy = HeadCopy;

        Node *temp = head;

        while(temp){
            TailCopy->next = new Node(temp->val);
            TailCopy = TailCopy->next;
            temp = temp->next;
        }

        TailCopy = HeadCopy;
        HeadCopy = HeadCopy->next;
        delete TailCopy;

        TailCopy = HeadCopy;
        temp = head;

        while(temp){
            TailCopy->random = find(head, HeadCopy, temp->random);
            TailCopy = TailCopy->next;
            temp = temp->next;
        }

        return HeadCopy;
    }
};