class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n= nums.size();
        int min_len=INT_MAX;

        for(int i=0;i<n;i++){

            int prefixsum=0;

            for(int j=i;j<n;j++){

                prefixsum+=nums[j];

                if(prefixsum>=target){
                    min_len = min(min_len, (j-i+1));
                    
                }
            }
        }

        if(min_len==INT_MAX){
            min_len=0;
            return min_len;
        }
        else{
            return min_len;
        }

    }
};