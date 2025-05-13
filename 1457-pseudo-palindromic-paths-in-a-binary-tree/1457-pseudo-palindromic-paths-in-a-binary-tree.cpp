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
int result = 0;

void solve(TreeNode*root, vector<int> temp)
{
    if(!root){
        return;
    }

    temp[root->val]++;

    if(root->left == NULL && root->right == NULL){ // leaf node --- we get one path now check whether it is palindrome or not 


        int odd_freq = 0;

        for(int i=1;i<=9;i++){
            
            if(temp[i] % 2 != 0){
                odd_freq++;
            }
        }

        if(odd_freq<=1){
            result++;
        } 
    }

    solve(root->left, temp);
    solve(root->right, temp);
}
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> temp(10,0);

        solve(root, temp);

        return result;
    }
};