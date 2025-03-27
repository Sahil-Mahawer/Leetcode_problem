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

ListNode* reverse(ListNode*curr, ListNode* prev){

    ListNode* next = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;

}


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* curr1 = reverse(l1, NULL);
        ListNode* curr2 = reverse(l2, NULL);

        ListNode *head = new ListNode(0);
        ListNode *tail = head;

        int carry = 0;
        int sum =0;

        while(curr1!=NULL && curr2!=NULL){

            sum = curr1->val + curr2->val+carry;
            tail->next = new ListNode(sum%10);
            carry = sum/10;
            tail = tail->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while(curr1){
            sum = curr1->val + carry;
            tail->next = new ListNode(sum%10);
            carry = sum/10;
            tail = tail->next;
            curr1 = curr1->next; 
        }

        while(curr2){
            sum = curr2->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            carry = sum/10;
            curr2 = curr2->next; 
        }

        while(carry){
            tail->next = new ListNode(carry%10);
            tail = tail->next;
            carry = carry/10;
        }

       head = reverse(head->next, NULL);

        return head;

       
    }
};