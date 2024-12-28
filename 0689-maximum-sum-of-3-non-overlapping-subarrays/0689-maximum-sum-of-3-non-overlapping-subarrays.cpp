class Solution {
public:

int helper(vector<int>& subarray,int count, int i, int k ){

    if(count==0){
        return 0;
    }

    if(i>=subarray.size()){
        return INT_MIN;
    }

    int take = subarray[i]+helper(subarray, count-1, i+k, k);

    int not_take = helper(subarray, count, i+1, k);

    return max(take, not_take);

}


  void solve(vector<int>& subarray, int count, int i,  int k, vector<int>& result) { // solve function decide whether to take subarray starts from "i" index or not;

    if(count==0){
        return;
    }

    if(i>=subarray.size()){
        return;
    }

    int take_i = subarray[i] + helper(subarray, count-1, i+k, k);
    
    int not_take_i = helper(subarray, count, i+1, k);

    if(take_i>=not_take_i){
        result.push_back(i);
        solve(subarray, count-1, i+k, k, result);
    }
    else{
        solve(subarray, count, i+1, k, result);
    }

    } 



    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        
        vector<int> subarray;

        int i=0;
        int j=0;
        int windowsum=0;

        while(j<nums.size()){
            windowsum+=nums[j];

            if(j-i+1==k){
                subarray.push_back(windowsum);
                windowsum -= nums[i];
                i++;
            }
            j++;
        }

        vector<int> result;
        solve(subarray, 3, 0, k, result);  //0 is starting index

        return result;
    }
};