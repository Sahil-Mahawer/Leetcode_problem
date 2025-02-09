class Solution {
public:

int rev(int num){
    
    int rev=0;

    while(num>0){
    int digit = num%10;
    rev = rev*10+digit;

    num = num/10;
    }

    return rev;

} 


    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;

         int MOD =1000000007;

        int result=0;

        int n = nums.size();

        for(int i=0;i<n;i++){

            nums[i] = nums[i]-rev(nums[i]); 
        }
        mp[nums[0]]=1;

        for(int j=1;j<n;j++){
            result = (result+mp[nums[j]])%MOD;
            mp[nums[j]]++;
        }
        return result;
    }
};