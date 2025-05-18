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
vector<TreeNode*> result;

TreeNode* solve(TreeNode* root, unordered_set<int> st){

    if(root == NULL){
        return NULL;
    }

    root->left = solve(root->left, st);
    root->right = solve(root->right, st);

    if(st.find(root->val) != st.end()){

        if(root->left != NULL){
            result.push_back(root->left);
        }

        if(root->right != NULL){
            result.push_back(root->right);
        }

        return NULL;
    }
    else{

        return root;

    }

}


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int> st;

        for(int i=0;i<to_delete.size();i++){
            st.insert(to_delete[i]);
        }

        solve(root, st);

        if(st.find(root->val) == st.end()){
            result.push_back(root);
        }

        return result;

    }
};