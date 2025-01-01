class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        int start = 0 , end = 0, total = 0, odd_count=0;
       

        // Atleast(k)
        while(end<n){

            if(nums[end]%2!=0){
                odd_count++;
            }

            while(odd_count==k){
                total += (n-end);

                if(nums[start]%2!=0)
                odd_count--;

                start++;
            }
            end++;
        }

        start = 0 , end = 0, odd_count = 0;
      
        int total2=0;
        k++;

        
         while(end<n){

            if(nums[end]%2!=0){
                odd_count++;
            }

            while(odd_count==k){
                total2 += (n-end);

                if(nums[start]%2!=0)
                odd_count--;

                start++;
            }
            end++;
        }

        return total-total2;
    }
};