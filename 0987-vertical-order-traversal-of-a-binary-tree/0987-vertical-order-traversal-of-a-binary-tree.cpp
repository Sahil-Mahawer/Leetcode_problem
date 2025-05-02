class Solution {
public:

void find(TreeNode* root, int pos, int& l , int& r)
{
    if(root==NULL)
    return;

    l = min(l, pos);
    r = max(r, pos);
      
    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    
    int l = 0, r = 0;

    find(root, 0, l, r);

    vector<vector<int>> positive_index(r + 1);
    vector<vector<int>> negative_index(abs(l) + 1);

    queue<TreeNode*> q;
    queue<int> index;

    q.push(root);
    index.push(0);

    while (!q.empty())
    {
        int size = q.size();
        vector<pair<int, int>> temp; // (pos, val)

        for (int i = 0; i < size; i++)
        {
            TreeNode* node = q.front(); q.pop();
            int pos = index.front(); index.pop();

            temp.push_back({pos, node->val});

            if (node->left)
            {
                q.push(node->left);
                index.push(pos - 1);
            }

            if (node->right)
            {
                q.push(node->right);
                index.push(pos + 1);
            }
        }

        // sort current level by horizontal position and value
        sort(temp.begin(), temp.end());

        for (int i = 0; i < temp.size(); i++)
        {
            int pos = temp[i].first;
            int val = temp[i].second;

            if (pos >= 0)
                positive_index[pos].push_back(val);
            else
                negative_index[abs(pos)].push_back(val);
        }
    }

    vector<vector<int>> ans;

    for (int i = negative_index.size() - 1; i >= 1; i--)
    {
        ans.push_back(negative_index[i]);
    }

    for (int i = 0; i < positive_index.size(); i++)
    {
        ans.push_back(positive_index[i]);
    }

    return ans;
}
};
