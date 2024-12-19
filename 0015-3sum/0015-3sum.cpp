class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;

        int n = nums.size();

        if(n<3)
        return ans;

        for(int i=0;i<n-2;i++){
            
            int find1 = 0-nums[i];

            int start = i+1;
            int end = n-1;

            while(start<end){

                if(nums[start]+nums[end]==find1){
                    ans.push_back(nums[i], nums[start], nums[end]);

                    while(start<end && nums[start]==nums[start+1]) start++;
                    while(start<end && nums[end]==nums[end-1]) end--;

                    start++;
                    end--;
                }

                else if(nums[start]+nums[end]>find1){
                end--;
                }

                else{
                start++;
                }
            }
        }
        return ans;
    }
};