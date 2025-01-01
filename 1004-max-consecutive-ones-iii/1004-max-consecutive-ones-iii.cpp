class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int count_0 = 0;
        int n = nums.size();
        unordered_map<int,int> freq;

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        if(freq[0]<=k){
            return nums.size();
        }

        int start = 0, end = 0, len=0;

        while(end<n){

            if(nums[end]==0){
                count_0++;
            }

            while(count_0>k){
                // len = max(len, (end-start));

                if(nums[start]==0)
                count_0--;

                start++;

            }
            len = max(len, (end-start+1));
            end++;
        }

        return len;
    }
};