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
unordered_map<string, int> mp;

vector<TreeNode*> result;

string solve(TreeNode* root){

    if(root == NULL){
        return "#";
    }

    string left = solve(root->left);
    string right = solve(root->right);

    string curr = to_string(root->val) + ',' + left + ',' + right;

    mp[curr]++;

    if(mp[curr] == 2){
        result.push_back(root);
    }

    return curr;
}

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        solve(root);

        return result;
    }
};