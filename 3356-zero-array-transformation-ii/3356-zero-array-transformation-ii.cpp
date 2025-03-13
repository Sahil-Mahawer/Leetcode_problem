class Solution {
public:

bool check_difference_array_technique(vector<int>& nums,vector<vector<int>>& queries, int k)
{
        int n = nums.size();
        vector<int> diff(n,0);

        for(int i=0;i<=k;i++){

            int l= queries[i][0];
            int r = queries[i][1];
            int x= queries[i][2];

            diff[l] += x;
            if(r+1 < n)
             diff[r+1] -= x;

        }
        int cum_sum = 0;

        for(int i=0;i<n;i++){
            cum_sum += diff[i];

            diff[i] = cum_sum;

            if(nums[i] - diff[i] > 0){
                return false;
            }
        }

    return true;

}

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
//  ------->>>> Brute Force Approach ------->>>>>>

        // int n = nums.size();
        // int count = 1;


        //  if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
        //             return 0;
        //       }
        

        // int q = queries.size();

        // for(int i=0;i<q;i++){
        //     int left =   queries[i][0];
        //     int right = queries[i][1];
        //     int diff  = queries[i][2];

        //     for(int j = left;j<=right;j++){
        //         nums[j] = nums[j] - diff;

        //         if(nums[j]<0){
        //             nums[j] = 0;
        //         }
        //     }

        //       if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
        //             return count;
        //       }

        //     count++;
            
        // }

        // return -1;


        int n = nums.size();
        int q = queries.size();

        if(all_of(begin(nums), end(nums),[] (int x) {return x == 0;})){
            return 0;
        }

        int start = 0;
        int end = q-1;

        int result = -1;

        while(start <= end){

            int mid = start+(end-start)/2;

            if(check_difference_array_technique(nums,queries,mid) == true){ // means array becomes 0
                result = mid+1;
                end = mid-1;
            }

            else{
                start = mid+1;
            }
        }

        return result;


    }
};