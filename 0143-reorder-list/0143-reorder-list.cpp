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
        

        // find the middle 
        ListNode *slow = head, *fast = head;

        while(fast!=NULL && fast->next!=NULL){

            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *newHead = slow->next;
        slow->next = NULL; // divide the linked list into two parts

        // first part start from "head"
        // and second part start from "newHead"

        // and now reverse the second list , which start from "newHead"

        ListNode *prev = NULL, *curr = newHead, *next = NULL;

        while(curr){

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } 

        // Now, "prev" is pointing to beginning of reversed list
        

        // and merge the second list to first list one by one 

        ListNode *t1 = head;
        ListNode *t2 = prev;

        while(t2!=NULL){
            
            ListNode *m1 = t1->next;
            ListNode *m2 = t2->next;
            
            t1->next = t2;
            t2->next = m1;
            t1 = m1;
            t2 = m2; 
        }

    }
};