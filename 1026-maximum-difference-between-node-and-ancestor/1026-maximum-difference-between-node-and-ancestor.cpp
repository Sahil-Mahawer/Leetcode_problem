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
int maxDiff;

// ik node prr fix rehke use left and right child se uss node ka max difference calculate krta hai 
void findMax(TreeNode* root, TreeNode* child){

    if(root == NULL || child == NULL)
    return;

    maxDiff = max(maxDiff, abs(root->val - child->val));

    findMax(root, child->left);
    findMax(root, child->right);

}

void solve(TreeNode* root){

    if(root == NULL)
    return;

    findMax(root, root->left);
    findMax(root, root->right);

    solve(root->left);
    solve(root->right);

}
    int maxAncestorDiff(TreeNode* root) {
        
        maxDiff = -1;

        solve(root);

        return maxDiff;
    }
};