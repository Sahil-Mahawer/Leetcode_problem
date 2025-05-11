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

void solve(TreeNode*root, int current, int &totalSum)
{
        if(!root)
            return;

        current = (current*10) + root->val;

        if(root->left == NULL && root->right == NULL){
        totalSum += current;
        return; 
        }

        solve(root->left, current, totalSum);
        solve(root->right, current, totalSum);
}


    int sumNumbers(TreeNode* root) {
        
        int totalSum = 0;
        solve(root,0,totalSum);

        return totalSum;
    }
};