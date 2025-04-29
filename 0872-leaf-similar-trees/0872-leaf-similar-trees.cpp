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

void sequence_1(TreeNode* root1,vector<int> &ans1){

        if(root1->left == NULL && root1->right == NULL){
            ans1.push_back(root1->val);
            return;
        }

        sequence_1(root1->left, ans1);
        sequence_1(root1->right, ans1);

    
}

void sequence_2(TreeNode* root2,vector<int> &ans2){

        if(root2->left == NULL && root2->right == NULL){
            ans2.push_back(root2->val);
            return;
        }

        sequence_2(root2->left, ans2);
        sequence_2(root2->right, ans2);

    
}

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        
        vector<int> ans1;
        vector<int> ans2;

        sequence_1(root1, ans1);

        sequence_2(root2, ans2);

        return ans1 == ans2 ;
    }
};