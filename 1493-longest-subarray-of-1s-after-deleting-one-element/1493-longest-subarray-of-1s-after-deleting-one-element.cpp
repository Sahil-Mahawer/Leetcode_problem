class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count_0 = 0;
        int k=1;
        int n = nums.size();
        unordered_map<int,int> freq;

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        // If the total number of zeros is less than or equal to k, the entire array can be flipped
        if(freq[0]<=k){
            return nums.size()-1;
        }

        int start = 0, end = 0, len=0;

        while(end<n){

            // Increment count of zeros if current element is 0
            if(nums[end]==0){
                count_0++;
            }

            // If count of zeros exceeds k, shrink the window from the left
            while(count_0>k){
               
                if(nums[start]==0)
                count_0--;

                start++;

            }
            len = max(len, (end-start+1));
            end++;
        }

        return len-1;
    }
};