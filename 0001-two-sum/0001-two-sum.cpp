class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size(),check ;
        vector<int>ans(2);
        for(int i=0;i<n;i++){
           check = target-nums[i];
            for(int j=i+1;j<=n-1;j++){
                if(nums[j]==check){
                    ans[0]=i;
                    ans[1]=j;
                    break;
                }
            }
        }
        return ans;

    }
};