class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(begin(nums), end(nums));

        int n = nums.size();

        int min_value = nums[0];

        int count = 1; // first subsequence

        for(int i=0; i<n; i++){
            
            if(nums[i] - min_value > k){
                count++;
                min_value = nums[i];
            }
        }

        return count;
    }
};