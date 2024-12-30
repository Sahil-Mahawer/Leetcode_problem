class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // ----->>> Brute Force Approach --->>

        // int n = nums.size();
        // int ans = -1;

        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]==nums[j] && abs(i-j)<=k){
        //             ans = true;
        //             break;
        //         }
        //     }
        // }
        // if(ans==-1){
        //     return false;
        // }
        // else{
        //     return ans;
        // }

        //  ---->>> Optimal Approach ----->>>>

        unordered_map<int,int> mpp;
        int n = nums.size();

        for(int i=0;i<n;i++){

            if(mpp.find(nums[i])!=mpp.end()){
                  int len = abs(i-mpp[nums[i]]);
                  if(len<=k)
                  return true;
            }
            mpp[nums[i]]=i;
        }
        return false;
    }
};