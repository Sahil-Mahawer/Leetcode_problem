/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    // used for storing parent node of current node 
    unordered_map<TreeNode*, TreeNode*> parent;  // declared globally we can use it without passing it in function

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        if (root->left != NULL) {
            parent[root->left] = root;
        }

        inorder(root->left);

        if (root->right != NULL) {
            parent[root->right] = root;
        }

        inorder(root->right);
    }

    void BFS(TreeNode* target, int k, vector<int>& result) {

        queue<TreeNode*> q;

        q.push(target);

        unordered_map<TreeNode*, bool> visited;

        visited[target] = true;
        
        int distance = 0;

        while (!q.empty()) {

            int n = q.size();

            if (distance == k) {
                break;
            }

            while (n--) {

                TreeNode* temp = q.front();
                q.pop();

                if (temp->left && visited[temp->left] == false) { 
                    // means temp ka left exist krta hai and vo abhi tkk visit nhi hua hai
                    q.push(temp->left);
                    visited[temp->left] = true;
                }

                if (temp->right && visited[temp->right] == false) { 
                    // means temp ka right exist krta hai and vo abhi tkk visit nhi hua hai
                    q.push(temp->right);
                    visited[temp->right] = true;
                }

                if (parent.find(temp) != parent.end() && visited[parent[temp]] == false) { 
                    // means present node ka parent present hai map mai (matlab exist krta hai) 
                    // and abhi tkk visit nhi hua h 
                    q.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }

            distance++;
        }

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> result;
        
        inorder(root);  // step 1: store parents using inorder traversal

        BFS(target, k, result);  // step 2: do level-order traversal from target to distance k

        return result; 
    }
};
