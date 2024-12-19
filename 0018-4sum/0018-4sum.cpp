class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i=0;i<n-3;i++){

            if(i>0 && nums[i]==nums[i-1]) continue;

            long long  find1 = (long long )target-nums[i];

            for(int j=i+1;j<n-2;j++){
                
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                long long  find2 = find1 - nums[j];

                int start = j+1 , end = n-1;

                while(start<end){
                    long long sum = nums[start]+nums[end];
                    if(sum==find2){
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});

                        while(start<end && nums[start]==nums[start+1]) start++;
                        while(start<end && nums[end]==nums[end-1]) end--;

                        start++;
                        end--;
                    }

                    else if(sum)>find2){
                        end--;
                    }

                    else{
                        start++;
                    }
                }
            }
           

        }
        return ans;
    }
};