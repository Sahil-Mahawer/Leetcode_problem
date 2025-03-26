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
    ListNode* deleteMiddle(ListNode* head) {

        if(head==NULL || head->next == NULL){
            return head;
        }
        
        ListNode *slow = head, *fast = head,  *pre_slow =  NULL;//new ListNode(0);
        // pre_slow->next = head;

        while(fast!=NULL && fast->next!=NULL){
            pre_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre_slow->next = slow->next;

        return head;

    }
};