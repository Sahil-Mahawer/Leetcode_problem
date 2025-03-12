class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int count_pos = 0;
        int count_neg = 0;
        int ans = 0;

        for(int i=0;i<nums.size();i++){

            if(nums[i]>0){
                count_pos++;
            }
            else if(nums[i]<0){
                count_neg++;
            }
        }

        ans = max(count_pos, count_neg);

        return ans;
    }
};