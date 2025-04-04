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
    int pairSum(ListNode* head) {
        
        int maxi = -1;

        vector<int> ans;
        ListNode *temp = head;

        while(temp){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int n = ans.size();

        for(int i=0;i<=(n/2)-1;i++){
            maxi = max(maxi, ans[i]+ans[n-1-i]);
        }

        return maxi;
    }
};