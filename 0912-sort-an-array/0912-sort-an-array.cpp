class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n= nums.size();

        for(int i=0;i<n-1;i++){
            int min_index= i;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[min_index])
                min_index=j;
            }
            swap(nums[min_index], nums[i]);
        }
           return nums;
    }
};