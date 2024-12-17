class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int n = nums.size();
        // if(n==0) return 0;
        // sort(nums.begin(), nums.end());
        // int count=1;
        // for(int i=0;i<n-1;i++){
        //     if(nums[i+1]==nums[i]) continue;
        //     if(nums[i+1]-nums[i]==1){
        //         count++;
        //     }
        //     else{
        //         count=1;
        //     }
            
        // }
        // return count;
        int n = nums.size();
    if (n == 0) return 0; // Handle empty array case
    
    sort(nums.begin(), nums.end());
    int count = 1, longest = 1;
    
    for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1] == nums[i]) continue; // Skip duplicates
        
        if (nums[i + 1] - nums[i] == 1) {
            count++;
        } else {
            count = 1; // Reset count for a new sequence
        }
        longest = max(longest, count);
    }
    return longest;
    }
};