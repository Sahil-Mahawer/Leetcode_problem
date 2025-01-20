class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        unordered_map<int,int> mpp;

        for(int i=0;i<arr.size();i++){
            mpp[arr[i]] = i;
        }

        int n = mat.size();
        int m = mat[0].size();
        int min_index = INT_MAX;

        for(int row=0;row<n;row++){        
        int last_index = INT_MIN;
            for(int col = 0; col<m;col++){

                int val = mat[row][col];
                int idx = mpp[val];
                last_index = max(last_index, idx);
            }
            min_index = min(min_index , last_index);

        }

        for(int col=0;col<m;col++){        
        int last_index = INT_MIN;
            for(int row = 0; row<n;row++){

                int val = mat[row][col];
                int idx = mpp[val];
                last_index = max(last_index, idx);
            }
            min_index = min(min_index , last_index);

        }
        return min_index;
    }
};