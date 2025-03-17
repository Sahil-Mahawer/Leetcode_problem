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
        
    // one way of solving it with taking vector(as space)

        // vector<int> check;

        // ListNode* temp = head;

        // while(temp){
        //     check.push_back(temp->val);
        //     temp = temp->next;
        // }

        // int n = check.size();

        // int l = 0, r = n-1;

        // while(l<r){
        //     if(check[l] == check[r]){
        //         l++;
        //         r--;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // return true;

        // --->>> Optimized way ----->>>>

        int count = 0;
        ListNode*temp = head;

        while(temp){
            count++;
            temp = temp->next;
        }

        count /=2;

        ListNode*prev = NULL, *curr = head;

        while(count){
            prev = curr;
            curr = curr->next;
            count--;
        }

        prev->next = NULL;   // at this point of time we have divided the linkedlist in two parts. 
        // one part start from head and other part starts from curr and now reverse the curr part and see if both linkedlist are same or not;

        // reverse the second linked list , curr is pointing it 
        ListNode  *front = NULL;

        prev = NULL;

        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }  

        // Now, head is pointing to first list
        // prev is pointing to second list

        ListNode *head1 = head, *head2 = prev;

        // check palindrome
        while(head1){
            if(head1->val != head2->val ){
                return false;
            }
            
                head1 = head1->next;
                head2 = head2->next;
            
        }

        return true;
    }
};