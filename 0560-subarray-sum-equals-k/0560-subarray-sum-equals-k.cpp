class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        // int n= nums.size();
        
        // int count=0;

        // for(int i=0;i<n;i++){
        //        int sum=0;
        //     for(int j=i;j<n;j++){
        //        sum=sum+nums[j];
        //        if(sum==k){
        //         count++;
        //        }
        //     }
        // }
        // return count;

        // ---->>> optimal ------>>>>>

        int total=0;

        int prefix_sum = 0;

        unordered_map<int,int> mp;

        mp[0] = 1;

        for(int i=0; i<arr.size(); i++){

         prefix_sum += arr[i];

         int rem = prefix_sum - k;

         if(mp.find(rem) != mp.end()){

            total += mp[rem];
         }

         mp[prefix_sum]++;

        }

        return total;
    }
};