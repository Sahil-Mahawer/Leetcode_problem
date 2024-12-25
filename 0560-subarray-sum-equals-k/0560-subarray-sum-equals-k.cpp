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

         int count=0;
    int prefixSum=0;

    map<int,int> mpp;

    mpp[0]=1;

    for(int i=0;i<arr.size();i++){
        prefixSum+=arr[i];

        int rem = prefixSum-k;

        count+=mpp[rem];
        mpp[prefixSum]+=1;
    }

    return count;
    }
};