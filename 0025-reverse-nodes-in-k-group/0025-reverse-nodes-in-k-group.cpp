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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        
        ListNode * first = new ListNode(0);
        first->next = head;

        head = first;

        ListNode * next = NULL;

        while(first->next){

            ListNode* temp = first;
            int count = 0;
            while (temp->next != NULL && count < k) {
                temp = temp->next;
                count++;
            }
            // If the number of nodes is less than k, do not reverse and exit.
            if (count < k) {
                break;
            }
            
            int x = k;

            ListNode *second = first->next;

            //first jisko point kr rha hai uske aage ki "k"nodes ko reverse krdo 
            ListNode* prev = first;
            ListNode*curr =first->next;



            while(x && curr){

                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                x--;
            }

            first->next = prev;
            second->next = curr;

            first = second;
        }

        first = head;
        head = head->next;
        delete first;

        return head;




    }
};