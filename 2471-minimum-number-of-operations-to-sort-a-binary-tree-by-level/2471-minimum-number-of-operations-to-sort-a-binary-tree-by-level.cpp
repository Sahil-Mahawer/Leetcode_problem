class Solution {
public:
    int result = 0;

    // Your original bubble swap logic applied on a full vector
    void findSwaps(vector<int>& arr) {
       
        vector<int>SortedVec(arr.begin(), arr.end());

        sort(begin(SortedVec), end(SortedVec));

        unordered_map<int,int>mp; // arr[i] -> i

        for(int i=0;i<arr.size();i++){
            mp[arr[i]] = i;
        }

        for(int i=0;i<arr.size(); i++){

            if(arr[i] == SortedVec[i]){
                continue; // no swap required
            }

            int index_of_sorted_element = mp[SortedVec[i]]; // index_of_sorted_element in arr

            mp[arr[i]] = index_of_sorted_element;

            swap(arr[i], arr[index_of_sorted_element]);
            result++;

        }
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelVals;  // fresh vector for each level

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); q.pop();
                levelVals.push_back(node->val);  // store current level's values

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Call your original logic on the level's values
            findSwaps(levelVals);
        }

        return result;
    }
};
