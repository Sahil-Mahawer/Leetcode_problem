class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        // Brute Force Approach 


        //  int flips = 0;

        // int n = nums.size();

        // for(int i=0;i<n; i++){

        //     if(nums[i] ==0){

        //         if(i+k-1>=n){
        //             return -1;
        //         }

        //         for(int j = i; j<=i+k-1; j++){

        //             if(nums[j] == 0){
        //                 nums[j] = 1;
        //             }
        //             else if(nums[j]==1){
        //                 nums[j] = 0;
        //             }
        //         }
        //         flips++;
        //     }
        
        // }

        // return flips;


            queue<int> q;

            int flips = 0;

            int n = nums.size();

            for(int i=0;i<n;i++){

                if(!q.empty() && q.front() < i){
                    q.pop();
                }

                if(q.size() % 2 == nums[i]) { // means if queue  size is even and nums[i] = 0 ... first of all queue size reprsents the number of flips ... and if number of flip is even  means q.size() %2 == 0 and nums[i] == 0 this means that nums[i] get flipped even times and it again becomes to 0 so we need to flip one more time to make nums[i] to 1;  and vice versa for 1 
                   
                    if(i+k-1 >= n){
                        return -1;
                    }

                    q.push(i+k-1);
                    flips++;
                }
            }

            return flips;
    }

};