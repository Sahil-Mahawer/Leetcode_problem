class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        int count = 1, longest = 1;

        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){

            if(nums[i] == nums[i+1]) continue;

            if(nums[i+1] - nums[i] == 1){

                count++;
            }
            else{

                count = 1;
            }

            longest = max(count,longest);
        }

        return longest;

    }
};