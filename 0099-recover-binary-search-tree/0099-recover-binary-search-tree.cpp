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


void inorder(TreeNode* root, vector<int> &ans){

    if(root == NULL)
    return;

    inorder(root->left, ans);

    ans.push_back(root->val);

    inorder(root->right, ans);

}

void restore(TreeNode* root, vector<int>&ans, int &index){

    if(root == NULL){
        return;
    }

    restore(root->left, ans, index);

    root->val = ans[index];

    index++;

    restore(root->right, ans, index);
}
    void recoverTree(TreeNode* root) {
        
        vector<int> ans;
        inorder(root, ans);

        sort(begin(ans), end(ans));

        int index = 0;
        restore(root, ans, index);
    }
};