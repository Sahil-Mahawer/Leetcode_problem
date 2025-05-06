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

int Count_Path_From_Node(TreeNode *root, int curr_sum, int targetSum){

        if(root == NULL)
        return 0;

        int count = 0;
        curr_sum += root->val;

        if(curr_sum == targetSum)
        count++;

        count +=  Count_Path_From_Node(root->left, curr_sum, targetSum);
        count +=  Count_Path_From_Node(root->right, curr_sum, targetSum);

        return count;
}


    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL)
        return 0;

        int pathFromRoot = Count_Path_From_Node(root, 0, targetSum);

        int pathFromLeft = pathSum(root->left, targetSum);
        int pathFromRight = pathSum(root->right, targetSum);

        return pathFromRoot + pathFromLeft + pathFromRight;
    }
};