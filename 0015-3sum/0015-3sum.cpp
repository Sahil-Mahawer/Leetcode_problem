class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
     sort(nums.begin(), nums.end());
     vector<vector<int>> ans;
     int  find, target = 0;
     int n = nums.size();
  

     for(int i=0; i<n-2; i++){

        if(i>0 && nums[i] == nums[i-1]) continue;

        find =  target - nums[i];

        int start = i+1;
        int end = n-1;

        while(start < end){

            if(find == nums[start] + nums[end]){
                ans.push_back({nums[i], nums[start], nums[end]});
            

            while(start<end && nums[start] == nums[start+1]) continue;
            while(start < end && nums[end] == nums[end-1]) continue;
            
            start++;
            end--;
            }

            else if(nums[start] + nums[end] > find){
                end--;
            }
            else{
                start++;
            }
        }
        
     }

     return ans;
    }
};