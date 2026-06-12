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
    void reorderList(ListNode* head) {
        
        ListNode *slow = head, *fast = head;

        ListNode *newHead = NULL;

        while(fast!=NULL && fast->next!= NULL){

            slow = slow->next;
            fast = fast->next->next;
        }

        newHead = slow->next;
        slow->next = NULL;

        // reverse second half od LL
        ListNode *curr = newHead, *prev = NULL, *fut = NULL;
        while(curr != NULL){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        } 

        ListNode *t1 = head;
        ListNode *t2 = prev;


        while(t2 != NULL){

            ListNode *m1 = t1->next;
            ListNode *m2 = t2->next;

            t1->next = t2;
            t2->next = m1;

            t1 = m1;
            t2 = m2;

        }

    }
};