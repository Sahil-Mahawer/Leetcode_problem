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
    int getDecimalValue(ListNode* head) {
        

        vector<int> vec;

        while(head != NULL){

            vec.push_back(head->val);
            head = head->next;
        }

        int n = vec.size();

        int decimal = 0;

        for(int i=0; i<n; i++){
            
            decimal = decimal*2 + vec[i];
        }

        return decimal;
    }
};