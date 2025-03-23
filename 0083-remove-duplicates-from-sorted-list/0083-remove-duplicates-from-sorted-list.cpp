class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        vector<int> ans;
        ans.push_back(head->val);  // Store first unique value
          
        ListNode* curr = head->next;

        while (curr != NULL) {
            if (ans.back() != curr->val) {
                ans.push_back(curr->val);
            }
            curr = curr->next;
        }

        // Rewrite values in the linked list
        curr = head;
        int index = 0;

        while (index < ans.size()) {
            curr->val = ans[index];
            index++;
            if (index < ans.size()) {
                curr = curr->next;
            }
        }

        // Ensure the last valid node correctly points to NULL
        curr->next = NULL;  

        return head;
    }
};
