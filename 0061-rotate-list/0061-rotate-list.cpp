/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // count number of nodes
        if(head == NULL || head->next == NULL){
             return head;
        }

        int count = 0;
        ListNode *temp = head;

        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        
        k = k%count;

        if(k==0){
            return head;
        }

        count = count-k;

        ListNode *curr = head, *prev = NULL;

        while(count){

            prev = curr;
            curr = curr->next;
            count--;
        }
        prev->next = NULL;

        ListNode* tail = curr;

        // second list ke last node prr lekr jaao 
        while(tail->next!=NULL){
            tail = tail->next;
        }

        tail->next = head;

        head = curr; 

         return head;

    }
};