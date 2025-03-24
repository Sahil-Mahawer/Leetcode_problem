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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *temp1 = list1, *temp2 = list2;
        ListNode*store = NULL;


        if(list1 == NULL){
            return list2;
        }

        if( list2 == NULL){
            return list1;
        }

      
        vector<int> ans;

        while(temp1 != NULL && temp2 != NULL){

            if(temp1->val <= temp2->val){
                ans.push_back(temp1->val);
                temp1 = temp1->next; 
            }
            else{
                ans.push_back(temp2->val);
                temp2 = temp2->next;
            }
        }

        while(temp1){
            ans.push_back(temp1->val);
            temp1= temp1->next;
        }

        while(temp2){
            ans.push_back(temp2->val);
            temp2= temp2->next;
        }

       ListNode* newHead = new ListNode(ans[0]);
        ListNode* curr = newHead;

        for(int i = 1; i < ans.size(); i++) {
            curr->next = new ListNode(ans[i]);
            curr = curr->next;
        }

        return newHead;
        
    }
};