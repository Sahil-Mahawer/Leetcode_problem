class Solution {
public:
int M  = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {

        int n = nums.size();

        sort(begin(nums), end(nums));

        int l =0, r = n-1;

        // vector<int> power(n);

        int result = 0;

        while(l <= r){

            if(nums[l] + nums[r] <= target){

                result = result + pow(2, r-l);
                result = result%M;
                l++; 
            }

            else{
                 
                 r--;
            }

        }
        
        return result;
    }
};