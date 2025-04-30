class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        stack<TreeNode*> s1; // left to right
        stack<TreeNode*> s2; // right to left

        s1.push(root);

        while (!s1.empty() || !s2.empty()) {
            vector<int> level;

            // Process s1: left to right
            while (!s1.empty()) {
                TreeNode* node = s1.top();
                s1.pop();
                level.push_back(node->val);

                // Push left first, then right (for right-to-left processing later)
                if (node->left) s2.push(node->left);
                if (node->right) s2.push(node->right);
            }

            if (!level.empty()) result.push_back(level);
            level.clear();

            // Process s2: right to left
            while (!s2.empty()) {
                TreeNode* node = s2.top();
                s2.pop();
                level.push_back(node->val);

                // Push right first, then left (for left-to-right processing later)
                if (node->right) s1.push(node->right);
                if (node->left) s1.push(node->left);
            }

            if (!level.empty()) result.push_back(level);
        }

        return result;
    }
};
