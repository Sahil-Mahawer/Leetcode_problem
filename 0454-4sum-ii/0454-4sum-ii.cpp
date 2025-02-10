class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {

        int n = nums1.size();
        int count=0;

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                freq[nums1[i] + nums2[j]]++;
            }
        }

        for (int k = 0; k < n; k++) {

            for (int l = 0; l < n; l++) {

                int target = -(nums3[l]+nums4[k]);

                if(freq.count(target)){
                    count = count+ freq[target];
                }
            }
        }

        return count;
    }
};