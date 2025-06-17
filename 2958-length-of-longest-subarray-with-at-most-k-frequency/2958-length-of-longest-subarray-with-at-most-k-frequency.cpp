class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        // unordered_map<int,int> count;
        // int n = nums.size();
        // int len = 0;

        // int start = 0;
        // int end = 0;

        // while(end<n){

        //     count[nums[end]]++;

        //     while(count[nums[end]]>k){
        //         count[nums[start]]--;
        //         start++;
        //     }
        //     len = max(len, (end-start+1));
        //     end++;
        // }
       
        // return len;

        unordered_map<int,int>mp;
        int len = INT_MIN;

        int i = 0, j = 0;

        int n = nums.size();

        while(j<n){
            
            mp[nums[j]]++;

            while(mp[nums[j]] > k){

                mp[nums[i]]--;
                i++;
            }
            len = max(len, j-i+1);

            j++;
        }

        return len;
    }
};