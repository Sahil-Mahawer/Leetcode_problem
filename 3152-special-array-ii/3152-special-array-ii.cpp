class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        vector<int> cum_sum(n,0);
        cum_sum[0] = 0; // starting point

        for(int i=1;i<n;i++){

            if(nums[i]%2 == nums[i-1]%2){
                cum_sum[i] = cum_sum[i-1]+1;
            }
            else
            {
                cum_sum[i] = cum_sum[i-1];
            }
        }

        vector<bool> result;

        for(int i=0;i<queries.size();i++){

            int from_i = queries[i][0];
            int to_i = queries[i][1];

            if(cum_sum[to_i] - cum_sum[from_i] == 0){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
            return result;
    }
};