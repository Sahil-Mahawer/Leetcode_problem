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


// ------->>>>>> Brute Force ----->>>> (Accepted)


// class Solution {
// public:


// void inorder(TreeNode* root, vector<int> &ans){

//     if(root == NULL)
//     return;

//     inorder(root->left, ans);

//     ans.push_back(root->val);

//     inorder(root->right, ans);

// }

// void restore(TreeNode* root, vector<int>&ans, int &index){

//     if(root == NULL){
//         return;
//     }

//     restore(root->left, ans, index);

//     root->val = ans[index];

//     index++;

//     restore(root->right, ans, index);
// }
//     void recoverTree(TreeNode* root) {
        
//         vector<int> ans;
//         inorder(root, ans);

//         sort(begin(ans), end(ans));

//         int index = 0;
//         restore(root, ans, index);
//     }
// };


// -----------------------------------------------//

class Solution {
public:
    void recoverTree(TreeNode* root) {
        
        TreeNode* curr = NULL;

        TreeNode* present = NULL, *last = NULL;

        TreeNode* first = NULL, *second = NULL;   // first and last is for mistake 

        while(root!=NULL){

            if(root->left == NULL){
                last = present;
                present = root;

                if(last && last->val > present->val){ // mistake
                        
                        if(first==NULL){
                            first = last;
                        }
                        second = present;
                }

                root = root->right;
            }

            else{

                    curr = root->left;

                    while(curr->right!= NULL && curr->right!=root){
                        curr = curr->right;
                    }

                    if(curr ->right == NULL){  // there is no link ... so make the link  .... not traversed left part

                            curr->right = root;
                            root = root->left; 
                    }

                    else{ // already traversed left part

                        curr->right = NULL;

                        last = present;
                        present = root;

                        if(last && last->val > present->val){

                            if(first == NULL){
                                first = last;
                            }

                            second = present;
                        }
                        root = root->right;
                    }   
            }
        }

        int num = first->val;
        first->val = second->val;
        second->val  = num;
    }
};