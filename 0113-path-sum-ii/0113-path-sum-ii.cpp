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
vector<vector<int>> result;

void ans(TreeNode * root, int Currsum, vector<int> temp, int &targetSum)
{

    if(!root)
    return;

    Currsum += root->val;
    temp.push_back(root->val);

    if(root->left == NULL && root->right == NULL){
        
        if(Currsum == targetSum){
            result.push_back(temp);
        }

        return;
    }

    ans(root->left, Currsum, temp, targetSum);
    
    ans(root->right, Currsum, temp, targetSum);

}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        int sum = 0;

        vector<int> temp;

        ans(root, sum, temp, targetSum);

        return result;
    }
};