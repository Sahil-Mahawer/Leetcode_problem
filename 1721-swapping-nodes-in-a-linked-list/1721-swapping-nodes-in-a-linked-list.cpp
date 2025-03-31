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
    ListNode* swapNodes(ListNode* head, int k) {
        
        int count = 0;
        int x = k;
        ListNode *temp = head;

        while(temp){
            count++;
            temp = temp->next;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        while(dummy && k){
            dummy = dummy->next;
            k--;
        }

        int end_node = count - x+1;

        ListNode *second = new ListNode(0);
        second->next = head;
        // end->next = head;

        while(end_node && second){
            second = second->next;
            end_node--;
        }
        // end = end->next;

        int store = dummy->val;
        dummy->val = second->val;
        second->val = store;

        return head;
    }
};