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

unordered_map<TreeNode*, TreeNode*> parent;

TreeNode* startNode = NULL;

void inorder(TreeNode *root, int start){  // this function find the startNode and parent node of all the nodes

    if(root == NULL)
    return; 

    if(root->val == start){
        startNode = root;
    }

    if(root->left != NULL){
        parent[root->left]  = root;
    }
    inorder(root->left, start);

    if(root->right != NULL){
        parent[root->right]  = root;
    }
    inorder(root->right, start);

}
    int amountOfTime(TreeNode* root, int start) {
        
        inorder(root, start);

        queue<TreeNode*> q;

        unordered_map<TreeNode*, bool> visited;

        q.push(startNode);

        visited[startNode] = true;

        int minutes = -1;


        while(!q.empty())
        {

            int n = q.size();
            
            while(n--){

                 TreeNode *temp = q.front();
                 q.pop();
                 
                if(temp->left && visited[temp->left]==false){  
                    // means temp ka left exist krta hai and vo abhi tkk visit nhi hua hai

                    q.push(temp->left);
                    visited[temp->left] = true;
                 }

                if (temp->right && visited[temp->right] == false) { 
                    // means temp ka right exist krta hai and vo abhi tkk visit nhi hua hai
                    q.push(temp->right);
                    visited[temp->right] = true;
                }

                if(parent.find(temp) != parent.end() && visited[parent[temp]] == false){

                    q.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
           }
           minutes++;
        }

        return minutes;
    }
};