class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int candidate1=0, candidate2=0, count1=0, count2=0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            
            if(count1==0){
                candidate1=nums[i];
                count1=1;
            }

            else if(count2==0){
                candidate2=nums[i];
                count2=1;
            }

            else if(candidate1==nums[i]){
                count1++;
            }

            else if(candidate2 == nums[i]){
                count2++;
            }

            else{
                count1--;
                count2--;
            }
        }

        // count the  candidate 
        count1=0, count2=0;
        for(int i=0;i<n;i++){
            
            if(candidate1 == nums[i]) count1++;

             if(candidate2 == nums[i]) count2++;
        }


        vector<int> ans;
       
            if(count1>n/3) {
                ans.push_back(candidate1);
            }

             if(count2>n/3  && candidate2 != candidate1){
                ans.push_back(candidate2);
            }
        

        return ans;
    }
};