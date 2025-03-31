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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode *curr = head;
        int count = 1;

        ListNode *odd_head = new ListNode(0), *odd_tail = odd_head;
        ListNode *even_head = new ListNode(0), *even_tail = even_head;

        while(curr){

            if(count%2!=0){
                odd_tail->next = curr;
                odd_tail = odd_tail->next; 
            }

            else{
                even_tail->next = curr;
                even_tail = even_tail->next;
            }

            curr = curr->next;
            count++;
        }
        even_tail->next = NULL;
        odd_tail->next = even_head->next;

        return odd_head->next;

       
    }
};