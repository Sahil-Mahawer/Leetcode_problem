class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {

        int n = nums.size();
       
        int max_difference = 0;

        int j=0;

        while(j<n){

            max_difference =  max(max_difference , abs(nums[j]-nums[(j+1)%n]));
            j++;
        }

        return max_difference;
    }
};