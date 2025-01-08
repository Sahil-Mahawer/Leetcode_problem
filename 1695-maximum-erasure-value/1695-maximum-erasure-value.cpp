class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int sum =0;
        int n = nums.size();
        unordered_set<int> unique;

        int start = 0, end =0;

        while(end<n){

            while(unique.find(nums[end])!=unique.end()){
                sum -=nums[start];
                unique.erase(nums[start]);
                start++;
            }
            unique.insert(nums[end]);
            sum +=nums[end];
            end++; 
        }
        return sum;
    }
};