class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int,int> mp;

        int result = 0;

        for(int i=0; i<nums.size(); i++){

            mp[nums[i]]++;
        }


        for(int i=0; i<nums.size(); i++){

            int minNum = nums[i];
            int maxNum = nums[i] + 1;

            if(mp.find(maxNum) != mp.end()){

                result = max(result, mp[minNum] + mp[maxNum]);
            }
        }

        return result;
    }
};