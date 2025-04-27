class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        
        int n = nums.size();

        int count = 0;

        for(int i = 0; i<=n-3;i++){
            
            int first = nums[i];
            int second = nums[i+1];
            int third = nums[i+2];

            if(first + third == second/2.0)
            count++;
        }

        return count;
    }
};