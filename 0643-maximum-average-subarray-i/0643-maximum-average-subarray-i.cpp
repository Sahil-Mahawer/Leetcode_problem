class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int l = 0;
        int start = 0; 
        int r = nums.size();

        int count = 0; 
        double result = -1e18;
        double sum =0;  

        while(start < r){

            count++; 
            sum += nums[start];

            if(count == k){
            
                result = max(result, sum/k);
                sum = sum - nums[l];
                l++;
                count--;
            }

           

            start++; 
        }

        return result;
    }
};