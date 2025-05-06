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
typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, ll>> q;   // ll := index 

        q.push({root, 0});

        ll maxi = 0;

        while(!q.empty())
        {

            int n = q.size();
            ll L = q.front().second;  // left most element at particulr level 
            ll R = q.back().second; // right most element at particulr level

            maxi = max(maxi, R-L+1); // R-L+1 :- gives how many element is between leftmost and rightmost node

            while(n--){

                auto[node, idx] = q.front();
                q.pop();
                
                if(node->left){
                    q.push({node->left, 2*idx+1});
                }

                if(node->right){
                    q.push({node->right, 2*idx+2});
                }

            }
        }

        return maxi;
    }
};