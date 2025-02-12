class Solution {
public:

int digits(int n){

int sum = 0;

    while(n>0){
        int dig = n%10;
        sum = sum+dig;
        n = n/10;
    }

    return sum;
}


    int maximumSum(vector<int>& nums) {
        
      
        int maxi = -1;

        unordered_map<int,int> mp; // digitsum -> number

        for(int i=0;i<nums.size();i++)
        {
            int digit_sum = digits(nums[i]);
            
            if(mp.find(digit_sum)!= mp.end()){
                maxi = max(maxi , nums[i]+mp[digit_sum]);
                mp[digit_sum] = max(nums[i], mp[digit_sum]);
            }

            else{
                mp[digit_sum] = nums[i];
            }
        }

       return maxi;
    }
};