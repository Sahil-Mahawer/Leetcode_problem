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
    bool isPalindrome(ListNode* head) {
        
        vector<int> check;

        ListNode* temp = head;

        while(temp){
            check.push_back(temp->val);
            temp = temp->next;
        }

        int n = check.size();

        int l = 0, r = n-1;

        while(l<r){
            if(check[l] == check[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};