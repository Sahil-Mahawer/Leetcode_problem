class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        
        vector<int> ones;
        int mod = 1e9 +7;

        for(int i=0;i<nums.size();i++){

            if(nums[i]==1){
                ones.push_back(i);  // storing indices where "1" is present 
            }
        }
 
        if(ones.empty()){  // if there is no one we cant split the array  
            return 0; 
        }

        long long result = 1;

        for(int i=1;i<ones.size();i++){

            long long count_0s = ones[i]-ones[i-1]-1; // finding count of zeroes between two consecutive ones ..  if there is N zeroes between two ones then there will be N+1 splits .. multiply all the splits 

            result = (result*(count_0s+1))%mod;
        }

        return result;
    }
};