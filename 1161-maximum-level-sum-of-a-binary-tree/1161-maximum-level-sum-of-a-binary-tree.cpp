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
    int maxLevelSum(TreeNode* root) {
        
        int level = 1;

        int ans = 1;

        
        int max_sum = INT_MIN;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int n = q.size(); 
            int sum = 0;

            while(n--){
                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }


             if(sum > max_sum){
                    max_sum = sum;
                    ans = level;
                }
                
            level =  level + 1;
        }

        return ans;
    }
};