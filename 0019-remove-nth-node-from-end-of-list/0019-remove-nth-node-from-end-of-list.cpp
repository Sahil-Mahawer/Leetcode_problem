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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *temp = head;
        int size = 0;

        while(temp != NULL){
            size++;
            temp = temp->next;
        }


        if(size == n){
            ListNode *node_to_delete = head;
            head = head->next;
            delete node_to_delete;
            return head;
        }

        int k = size - n;

        k = k-1; 
        temp = head;

        while(k){
            temp = temp->next;
            k--;
        }

        ListNode *Node_to_delete = temp->next;
        temp->next = Node_to_delete->next;

        delete Node_to_delete;

        return head;
    }
};