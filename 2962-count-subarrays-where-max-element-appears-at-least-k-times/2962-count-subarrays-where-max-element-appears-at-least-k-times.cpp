class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        int max_element = INT_MIN;

        for(int i=0;i<n;i++){

            max_element = max(max_element, nums[i]);
        }

        int start=0, end=0;
        int max_count=0;
        long long  total = 0;

        while(end<n){
            
            if(nums[end]==max_element){
                max_count++;
            }

            while(max_count==k){
                total+= (long long) (n-end);
                
                if(nums[start]==max_element){
                max_count--;
                }

                start++;
            }
            end++;
        }
        return total;
    }
};