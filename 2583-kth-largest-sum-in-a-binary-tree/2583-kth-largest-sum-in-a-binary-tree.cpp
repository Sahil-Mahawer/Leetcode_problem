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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        priority_queue<long long> maxHeap;

        queue<TreeNode*> q;

        q.push(root);


        while(!q.empty()){

            int n = q.size();

            long long sum = 0;

            while(n--){

                TreeNode* temp = q.front();
                q.pop();

                sum+= temp->val;

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }
            maxHeap.push(sum);
        }

        if(maxHeap.size() < k)
        return -1;

        long long ans = 0;

        while(k--){
            ans = maxHeap.top();
            maxHeap.pop();
        }

        return ans;
    }
};