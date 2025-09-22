class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int,int> mp;

        int max_freq = 0;

        int ans = 0;

        for(int i:nums){

            mp[i]++;
            max_freq = max(max_freq, mp[i]);
        }

        for(auto it = mp.begin(); it!=mp.end(); it++){
            
            if(max_freq == it->second){

                ans += it->second;
            }
        }

        return ans;
    }
};