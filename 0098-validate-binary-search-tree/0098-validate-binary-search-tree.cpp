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
// vector<int> ans;

// void inorder(TreeNode* root){

//     if(root == NULL){
//         return;
//     }

//     inorder(root->left);

//     ans.push_back(root->val);

//     inorder(root->right);

// }


bool BST(TreeNode* root, long long &prev){

    if(root == NULL)
    return true;

    bool left = BST(root->left, prev);
    if(left == false){
        return false;
    }

    // checking for current node 
    if(root->val <= prev){
        return false;
    }

    prev = root->val;

    return BST(root->right, prev);
}


    bool isValidBST(TreeNode* root) {
        
        // inorder(root);

        // for(int i=1;i<ans.size(); i++){

        //     if(ans[i] <= ans[i-1]){
        //         return false;
        //     }
        // }

        // return true;



        long long prev = LLONG_MIN;

        return  BST(root, prev);

    }
};