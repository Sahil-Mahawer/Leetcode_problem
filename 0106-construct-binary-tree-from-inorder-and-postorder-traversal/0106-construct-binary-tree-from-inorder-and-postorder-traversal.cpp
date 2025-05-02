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

// In = refers to inorder

// This functions find the position of root in inorder 
int find(vector<int> inorder, int target, int In_start, int In_end)  
{

    for(int i=In_start;i<=In_end;i++)
    {

        if(inorder[i] == target){
            return i;
        }
    }

    return -1;
}


// In = refers to inorder
TreeNode * tree(vector<int>& postorder,vector<int>& inorder, int In_start, int In_end, int index)
{


    if(In_start > In_end)
    {
        return NULL;
    }


    TreeNode *root = new TreeNode(postorder[index]);

    int pos = find(inorder, postorder[index], In_start, In_end);

    root->right = tree(postorder, inorder, pos+1, In_end, index-1);

    root->left = tree(postorder, inorder, In_start, pos-1, index - (In_end - pos)-1);

    return root;

}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int p = postorder.size();

        int n = inorder.size();

          // here first 0 in below tree function  is = starting index of inorder
         // and n-1 is = ending index of inorder
        
        // and for postorder we start from end ... as postorder means --> (left right Node) ....
        // so last node in postorder represent the root node 

        return tree(postorder, inorder, 0/*starting index*/, n-1/* ending index*/, p-1/* starting index of postorder*/); 

    }
};