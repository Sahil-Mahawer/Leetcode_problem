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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        int prefix_sum = 0;

        unordered_map<int,ListNode*> mpp;

        ListNode *dummy = new ListNode(0);

        dummy->next = head;  // (dummy node)0 -> 1 -> 2 -> -3 -> 3 -> 1

        mpp[0] = dummy;

        while(head!=NULL){

            prefix_sum += head->val;

            if(mpp.find(prefix_sum)!=mpp.end()){

                ListNode *start = mpp[prefix_sum];
                ListNode *temp = start;

                int p_sum  = prefix_sum;

                while(temp!=head){
                    temp = temp->next;
                    p_sum += temp->val;

                    if(temp!=head){
                        mpp.erase(p_sum);
                    }
                }
                start->next = head->next;
            }
            else{
                mpp[prefix_sum] = head;
            }

            head = head->next;
        }

        return dummy->next;
    }
};