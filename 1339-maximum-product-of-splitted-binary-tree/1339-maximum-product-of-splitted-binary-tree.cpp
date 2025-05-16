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

long long SUM = 0; // totalSum

long long MaxProduct = 0;

const int MOD = 1e9 + 7;

int totalSum(TreeNode* root){

    if(root == NULL)
    return 0;

    int leftSubtree = totalSum(root->left);
    int rightSubtree = totalSum(root->right);

    int sum    =   root->val + leftSubtree + rightSubtree;

    return sum;
}

long long find(TreeNode* root)
{

    if(root == NULL)
    return 0;

    long long left = find(root->left);
    long long right = find(root->right);

    long long currentSubtree_Sum = root->val + left + right;

    long long remainingSubtree_Sum = SUM  -  currentSubtree_Sum;   // totalSum  - currentSubtree_Sum;

    MaxProduct = max(MaxProduct,currentSubtree_Sum *  remainingSubtree_Sum);

    return currentSubtree_Sum;
}
    int maxProduct(TreeNode* root) {

       SUM = totalSum(root);

       find(root);

       return MaxProduct % MOD;
    }
};