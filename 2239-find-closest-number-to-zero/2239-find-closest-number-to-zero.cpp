class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        
        vector<pair<int,int>> diff;
        int n = nums.size();
        int ans;

        for(int i=0;i<n;i++){
            diff.push_back({abs(nums[i]-0), nums[i]});
        }

        sort(diff.begin(), diff.end());

        ans = diff[0].second;

        for(int i=0;i<n-1;i++){ 
    
            if(diff[i].first==diff[i+1].first){
                ans =  max(diff[i].second, diff[i+1].second);
            }
            else{
                break;
            }
        }

         return ans;
    }
};