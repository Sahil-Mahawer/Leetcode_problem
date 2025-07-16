class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int countEven = 0;
        int countOdd  = 0;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] %2 ==0){
                countEven++;
            }
            else{
                countOdd++;
            }
        }


        int parity = nums[0]%2;
        int alternating = 1;

        for(int i=0; i<nums.size(); i++){

            int currParity = nums[i]%2;

            if(currParity != parity){
                alternating++;
                 parity = currParity ;
            }
        }

        return max({countEven, countOdd,alternating});
    }
};