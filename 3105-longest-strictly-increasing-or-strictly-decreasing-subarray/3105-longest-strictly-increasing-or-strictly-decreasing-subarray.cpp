class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
     
       
        int n = nums.size();

        int len1 = 0;
        int len2 = 0;

        for(int i=0;i<n;i++){

             int a = INT_MIN;
             int b = INT_MAX;

            for(int j=i;j<n;j++){

                if(nums[j]>a){
                    a = nums[j];
                    len1 = max(len1 , j-i+1);
                }
                else{
                    break;
                }

            }


        }

         for(int i=0;i<n;i++){

            int a = INT_MIN;
            int b = INT_MAX;

            for(int j=i;j<n;j++){

                if(nums[j]<b){
                    b = nums[j];
                    len2 = max(len2 , j-i+1);
                }
                else{
                    break;
                }

            }


        }


        return max(len1 , len2);

    }
};