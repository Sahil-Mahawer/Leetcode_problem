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
int sum = 0;

void find(TreeNode* root, int low, int high){

        if(!root){
            return;
        }
        
        if(root->val > low && root->val > high){
            rangeSumBST(root->left, low, high);
        }
        else if(root->val < low && root->val < high){
            rangeSumBST(root->right, low, high);
        }


        else{
             // if element is in range .. do preorder to check all numbers in left side and right side wich are in range 
            rangeSumBST(root->left, low, high);

            sum += root->val;

            rangeSumBST(root->right, low, high);
        }
}


    int rangeSumBST(TreeNode* root, int low, int high) {
        
        
        find(root, low, high);
        return sum;

    }
};