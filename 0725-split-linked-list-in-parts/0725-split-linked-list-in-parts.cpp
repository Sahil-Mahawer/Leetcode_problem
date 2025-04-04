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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        ListNode *temp = head;

        int L = 0;  // lenght of linked list 

        while(temp){
            L++;
            temp = temp->next;
        }

        int nodes_in_each_bucket = L/k;
        int extra_nodes = L%k;

        ListNode *curr = head;
        ListNode *prev = NULL;

        vector<ListNode*> ans(k, NULL);

        for(int i=0;i<k;i++){

            ans[i] = curr;

            for(int count = 1; count<=nodes_in_each_bucket +(extra_nodes >0 ? 1:0); count++){
                prev = curr;
                curr = curr->next;
            }

            if(prev)
            prev->next = NULL;
            extra_nodes--;
        }

        return ans;
    }
};