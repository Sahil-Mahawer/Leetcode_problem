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
        
        ListNode*temp = head;
        int total_node= 0;

        while(temp!=NULL){
            total_node++;
            temp = temp->next;
        }

        int node_to_delete = total_node - n;  // froms starting 

        temp = head;

        if(node_to_delete == 0){
            ListNode * newhead = head->next;
            delete head;
            return newhead;
        }
    
        for(int i=0;i<node_to_delete-1;i++){   //  Traverse to the node before the one to delete
            temp = temp->next;
        }

        ListNode* rem_node = temp->next;
        temp->next = rem_node->next;
        delete rem_node;

        return head;
    }
};