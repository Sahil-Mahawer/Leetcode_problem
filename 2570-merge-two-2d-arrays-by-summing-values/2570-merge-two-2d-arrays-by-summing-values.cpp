class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        vector<vector<int>> result;

        unordered_map<int,int> mpp;

        for(int i=0;i<nums1.size();i++){

            int id = nums1[i][0];
            int val = nums1[i][1];

            mpp[id] += val; 
        }

         for(int i=0;i<nums2.size();i++){

            int id = nums2[i][0];
            int val = nums2[i][1];

            mpp[id] += val; 
        }

        for(auto it = mpp.begin();it!=mpp.end();it++){

            result.push_back({it->first, it->second});
        }

        sort(begin(result), end(result));

        return result;
    }
};