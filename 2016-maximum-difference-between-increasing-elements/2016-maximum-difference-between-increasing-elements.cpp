class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int max_diff = INT_MIN;
    

        int n =nums.size(); 

        int min_element = nums[0];


        for(int j=1; j<n; j++){

            if(nums[j] > min_element){

                max_diff = max(max_diff, nums[j] - min_element);

            }
            else{

                min_element = nums[j];

            }
        }
        
        return max_diff;
      
    }
};