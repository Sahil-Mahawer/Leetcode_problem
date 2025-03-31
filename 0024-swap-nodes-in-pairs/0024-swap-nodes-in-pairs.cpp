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
    ListNode* swapPairs(ListNode* head) {

        ListNode *first = new ListNode(0);
        first->next = head;
        head = first;

        ListNode *next = NULL;

        while(first->next != NULL){

            int x = 2;
            ListNode *second = first->next;

            ListNode * prev = first;
            ListNode * curr = first->next;

            while(curr && x){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next; 
                x--;
            }
            first->next = prev;
            second->next = curr;

            first = second;
        } 

        // first = head;
        // head = head->next;
        // delete first;

        // return head;

        return head->next;
    }
};