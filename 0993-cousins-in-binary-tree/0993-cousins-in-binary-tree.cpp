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

bool parent(TreeNode * root, int x, int y){

    if(root == NULL){
        return false;
    }

    if(root->left != NULL && root->right != NULL){

        if(root->left->val == x && root->right->val == y)
        return true;

        if(root->left->val == y && root->right->val == x)
        return true; 
    }

    return  parent(root->left, x, y) || parent(root->right, x, y);
}
    bool isCousins(TreeNode* root, int x, int y) {
        

        // find the level
        queue<TreeNode*> q;

        q.push(root);

        int l1 = -1, l2 = -1;
        int level = 0;

        while(!q.empty()){

            int n = q.size();

            while(n--){

                TreeNode *temp = q.front();
                q.pop();

                if(temp->val == x){
                    l1 = level;
                }

                if(temp->val == y){
                    l2 = level;
                }

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
            }

            level++;

            if(l1 != l2) //same level prr nhi hai 
            return false;

            if(l1 != -1 && l2 != -1){  // dono ke liya level mill gay honge
                break;
            }
        }

        // jbb dono same level prr hai toh check kro ki parent same ha ya nhi

        // parent same hai ya nhi 
        return !parent(root, x, y);   // agrr dono ke parent same hote ha toh we will return false and if agrr dono ke parent allg hote hai toh we will return true;
    }
};