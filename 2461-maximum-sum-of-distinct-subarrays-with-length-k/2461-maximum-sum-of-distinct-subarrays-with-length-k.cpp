class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

       int start = 0, end = 0, n = nums.size(), count=0 ;
       long long max_sum=0, sum=0;
        unordered_map<int,int> freq;

       while(end<n){

        sum = sum+nums[end];
        freq[nums[end]]++;
        count++;

        while(freq[nums[end]]>1){

            sum = sum-nums[start];

            freq[nums[start]]--;

            start++;

            count--;
        }
        
        while(count==k){

            max_sum = max(max_sum,sum);

            sum = sum-nums[start];

            freq[nums[start]]--;

            count--;

            start++;
        
        }
            end++;
        }
        
        
    
       return max_sum;
    }
};