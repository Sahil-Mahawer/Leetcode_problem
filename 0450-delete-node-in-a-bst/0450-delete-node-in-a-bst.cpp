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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL){
            return NULL;
        }

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }

        else if(key  > root->val){
            root->right = deleteNode(root->right, key);
        }

        else{  // target found

            //  1.  and if it is a leaf node
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            else if(root->right == NULL){  //2.  if only left child exist of target

                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

             else if(root->left == NULL){  //3.  if only right child exist of target

                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
        
            else{  // 4 if both child exist of target

                TreeNode* parent = root;  // here root means our target which we want to delete. 
                TreeNode* child = root->left;

                while(child->right){
                    parent = child;
                    child = child->right;
                } 

                if(parent != root){
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }

                else{  // if parent == child
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }

            return root;
    }
};