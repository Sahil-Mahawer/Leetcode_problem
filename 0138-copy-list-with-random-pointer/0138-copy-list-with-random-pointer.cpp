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

// Node * find(Node *curr1, Node* curr2, Node* x){

//     while(curr1 != x){
//         curr1 = curr1->next;
//         curr2 = curr2->next;
//     }
//     return curr2;
// }

    Node* copyRandomList(Node* head) {

         if (!head) return nullptr;
        
        // Node *headcopy = new Node(0);
        // Node *tailcopy = headcopy;

        // Node *temp = head;

        // // Clone Created without Random Pointer
        // while(temp!=NULL){
        //     tailcopy->next = new Node(temp->val);
        //     tailcopy = tailcopy->next;
        //     temp = temp->next;
        // }
        // tailcopy = headcopy;
        // headcopy = headcopy->next;
        // delete tailcopy;  // dummy node 0 deleted

        // // Assign Random Pointer to Clone LL
        // tailcopy = headcopy;
        // temp = head;  // reset temp back to the head of original list

        // while(temp!=NULL){
        //     tailcopy->random = find(head, headcopy, temp->random);
        //     temp = temp->next;
        //     tailcopy = tailcopy->next;
        // }  

        // return headcopy;



        Node *headcopy = new Node(0);
        Node *tailcopy = headcopy;

        Node *temp = head;

        while(temp){
            tailcopy->next = new Node(temp->val);
            temp = temp->next;
            tailcopy = tailcopy->next;
        }

        tailcopy = headcopy;
        headcopy = headcopy->next;
        delete tailcopy;

        tailcopy = headcopy;

        Node *curr1 = head, *curr2 = headcopy;
        Node *front1, *front2;

        // inserting clone linkedlist into original linkedlist
        while(curr1){
            front1 = curr1->next;
            front2 = curr2->next;

            curr1->next = curr2;
            curr2->next = front1;

            curr1 = front1;
            curr2 = front2;
        }
        curr1 = head;

        // creating random pointer
        while(curr1){

            curr2 = curr1->next;

            if(curr1->random){
                curr2->random = curr1->random->next;
            }

            curr1 = curr2->next; // curr1 always point to original linkedlist 
        }

        // disconnect original and clone linkedlist with random pointer
        curr1 = head;

        while(curr1->next){
            front1 = curr1->next;
            curr1->next = front1->next;
            curr1 = front1;
        }

        return headcopy;
    }
};