class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> mpp(nums.begin(), nums.end());

        int k = mpp.size();

        int start = 0, end = 0, count=0, total=0;
        unordered_map<int,int> freq;
        while(end<n){
            
        freq[nums[end]]++;

        if(freq[nums[end]]==1){
            count++;
        }

        while(count==k){
            total += (n-end);

            freq[nums[start]]--;

            if(freq[nums[start]]==0){
                count--;
            }
            start++;
        }
        end++;
        }

        return total;
        
    }
};