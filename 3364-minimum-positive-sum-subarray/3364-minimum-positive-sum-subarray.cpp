class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();
        long long  mini = INT_MAX;
        // long long prefix = 0;
        

        for(int i=0;i<n;i++){
            long long prefix = 0;
            
            int count =0;
            
            for(int j=i;j<n;j++){

                prefix = prefix+nums[j];
                count++;
                if(count>=l && count<=r && prefix>0){
                    mini = min(prefix , mini);

                   
                }
                
                
            }
        }
        return (mini == INT_MAX)? -1:mini;
    }
};