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
    vector<int> largestValues(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }
        queue<TreeNode*> q;

        q.push(root);

        vector<int> ans;

        while(!q.empty()){

            priority_queue<int> pq;

            int size = q.size();

            for(int i=0; i<size; i++){

                TreeNode *temp = q.front();
                q.pop();

                pq.push(temp->val);

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }

            }

            ans.push_back(pq.top());
            
        }

        return ans;
    }
};