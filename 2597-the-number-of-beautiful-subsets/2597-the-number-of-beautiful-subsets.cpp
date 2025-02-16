class Solution {
public:

void subset(vector<int>& nums, int k, int &result , int index , unordered_map<int,int> &freq )
{

   if(index == nums.size()){
     result++;
     return;
   }

   // not include
   subset(nums, k ,result, index+1, freq);

   // include

   if(freq[nums[index]-k]==0 && freq[nums[index]+k] ==0){

    freq[nums[index]]++;

    subset(nums, k ,result, index+1, freq);

     freq[nums[index]]--;
   }

}


    int beautifulSubsets(vector<int>& nums, int k) {
        
        int result = 0;
        int index = 0;
        
        unordered_map<int,int> freq;

        subset(nums, k , result , index , freq);

        return result - 1;
    }
};