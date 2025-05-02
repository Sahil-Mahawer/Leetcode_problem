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

TreeNode* tree(vector<int> &preorder, vector<int> &inorder, int In_start, int In_end,  int index )
{
            if(In_start > In_end)
            return NULL;

            TreeNode *root = new TreeNode(preorder[index]);   // first node in preoder will always be a root node

            int pos  = find(inorder, preorder[index], In_start, In_end); // find positon of root in inorder

            // left part of root node
            root->left = tree(preorder, inorder, In_start, pos-1, index+1);  // index+1 ==> this index is of next element in preorder of left part 

            // right part of root node
            root->right = tree(preorder, inorder, pos+1, In_end, index+(pos-In_start)+1);  // index+(pos-In_start)+1 ===> this index is of next element in preorder of right part 

            return root;
}



    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();

        // here first 0 in below tree function  is = starting index of inorder
        // and n-1 is = ending index of inorder

    return tree( preorder,inorder,  0/*starting index*/, n-1 /* ending index*/, 0 /* starting index of preoder*/);

      
    }
};