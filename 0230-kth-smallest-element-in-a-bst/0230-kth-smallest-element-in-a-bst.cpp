/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int prev = INT_MIN;
    int count = 0;
    int ans = -1;

    void BST(TreeNode* root, int& k) {

        if (!root)
            return;

        BST(root->left, k);

        count++;
        if (count == k) {
            ans = root->val;
        }

        prev = root->val;

        BST(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {

        BST(root, k);

        return ans;
    }
};