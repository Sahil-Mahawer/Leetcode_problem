class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0, difference;
        // int mini = INT_MAX, maxi=INT_MIN;
        int n = nums.size();

        for(int i=0;i<n;i++){
             int mini = INT_MAX, maxi=INT_MIN;
            for(int j=i;j<n;j++){
                
                maxi =  max(maxi, nums[j]);
                mini = min(mini,nums[j]);

                difference = maxi-mini;

                sum = sum+difference;
               
            }
        }

        return sum;
    }
};