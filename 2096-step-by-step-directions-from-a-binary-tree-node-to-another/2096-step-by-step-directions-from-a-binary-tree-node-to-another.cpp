/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, int start, int dest) {

        if (root == NULL)
            return NULL;

        if (root->val == start || root->val == dest)
            return root;

        TreeNode* leftN = lowestCommonAncestor(root->left, start, dest);
        TreeNode* rightN = lowestCommonAncestor(root->right, start, dest);

        if (leftN != NULL && rightN != NULL)
            return root;

        if (leftN != NULL)
            return leftN;

        return rightN; // rightN != NULL
    }

    bool findPath(TreeNode * LCA, int target, string &path)
    {

        if(LCA == NULL)
        return false;

        if(LCA -> val == target) // hmee target mill gya hai abb orr path dhundne ki jrruurt nhi h 
        return true;

        // explore left ... agrr nhi milla hai toh 
        path.push_back('L');
        if (findPath(LCA -> left, target, path) == true){
            return true;
        }
        path.pop_back(); // backtrack

        // explore right
        path.push_back('R');
        if(findPath(LCA->right, target, path) == true){
            return true;
        }
        path.pop_back(); // backtrack

        return false;
    }



    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);

        string LCA_to_startValue = "";
        string LCA_to_destValue = "";

        findPath(LCA, startValue, LCA_to_startValue);
        findPath(LCA, destValue, LCA_to_destValue);

        string result = "";

        for(int i=0; i<LCA_to_startValue.size(); i++)
        {
            result.push_back('U');
        }

        result += LCA_to_destValue;

        return result;
    }
};