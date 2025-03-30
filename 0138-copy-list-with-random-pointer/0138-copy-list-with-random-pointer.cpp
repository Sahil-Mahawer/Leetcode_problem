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

Node * find(Node *curr1, Node* curr2, Node* x){

    while(curr1 != x){
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return curr2;
}

    Node* copyRandomList(Node* head) {
        
        Node *headcopy = new Node(0);
        Node *tailcopy = headcopy;

        Node *temp = head;

        while(temp!=NULL){
            tailcopy->next = new Node(temp->val);
            tailcopy = tailcopy->next;
            temp = temp->next;
        }
        tailcopy = headcopy;
        headcopy = headcopy->next;
        delete tailcopy;  // dummy node 0 deleted

        tailcopy = headcopy;
        temp = head;  // reset temp back to the head of original list

        while(temp!=NULL){
            tailcopy->random = find(head, headcopy, temp->random);
            temp = temp->next;
            tailcopy = tailcopy->next;
        }  

        return headcopy;

    }
};