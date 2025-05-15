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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        

        if(depth == 1){

            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode*> q;

        q.push(root);

        int curr_depth = 1;



        while(!q.empty()){

            int n = q.size();

            if(curr_depth == depth-1){

                for(int i=0; i<n; i++){

                    TreeNode* temp = q.front();
                    q.pop();

                    TreeNode* original_left = temp->left;
                    TreeNode*original_right = temp->right;

                    temp->left = new TreeNode(val);
                    temp->left->left = original_left;

                    temp->right = new TreeNode(val);
                    temp->right->right = original_right;
                }
                break;
            }

            while(n--){

                TreeNode *curr = q.front();
                q.pop();

                if(curr->left)
                q.push(curr->left);

                if(curr->right){
                    q.push(curr->right);
                }
            }

            curr_depth++;

        }

        return root;
    }
};