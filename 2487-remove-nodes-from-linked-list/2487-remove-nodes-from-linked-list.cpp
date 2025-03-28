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

ListNode * reverse(ListNode* head ){

    ListNode *curr = head, *prev = NULL, *next = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next; 
    }

    return prev;
}
    ListNode* removeNodes(ListNode* head) {
        
        head = reverse(head);

        int max_node = -1;

        ListNode *curr = head, *prev = NULL;

        while(curr!=NULL){
            
            max_node = max(max_node, curr->val);

            if(curr->val < max_node){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
            prev = curr;
            curr = curr->next; 
            }
        }

        head = reverse(head);

        return head;

        
    }
};