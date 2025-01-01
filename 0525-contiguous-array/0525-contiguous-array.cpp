class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();

        unordered_map<int,int> mpp;

        int prefixsum=0;
        mpp[0]=-1;

        int max_len = 0;

        for(int i=0;i<n;i++){

            if(nums[i]==0){
                prefixsum += -1;
            }
            else{
                prefixsum += 1;
            }

            if(mpp.find(prefixsum)!=mpp.end()){
                max_len = max(max_len, i-mpp[prefixsum]);
            }
            else
            {
            mpp[prefixsum]=i;
            }
        }

        return max_len;
    }
};