/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

class box{

    public:
    bool BST;
    int sum;
    int mini, maxi;

    box(int data){
        BST = 1;
        sum = data;
        mini = INT_MAX;
        maxi = INT_MIN;
    }
};

box* find(TreeNode* root, int &totalsum){

    if(root == NULL){
        return new box(0);
    }

    else{

        box* lefthead = find(root->left, totalsum);
        box* righthead = find(root->right, totalsum);

        if(lefthead->BST == 1 && righthead->BST == 1 && lefthead->maxi < root->val && righthead->mini >
        root->val){

                box* head = new box(root->val);
                head->sum  += lefthead->sum + righthead->sum;
                head->mini = min(root->val, lefthead->mini);   
                head->maxi = max(root->val, righthead->maxi);
                totalsum = max(head->sum, totalsum);
                return head;
        }
        else{

            lefthead->BST = 0;
            return lefthead;
        }
    }
}
    int maxSumBST(TreeNode* root) {
        

        int totalsum = 0;
        find(root, totalsum);

        return totalsum;
    }
};