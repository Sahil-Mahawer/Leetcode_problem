class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        unordered_map<int,int> mp;

        // int val = -1;

        int ans = -1;

        for(int i=0; i<arr.size(); i++){

            mp[arr[i]]++;
        }

        for(auto it = mp.begin(); it!= mp.end(); it++){

             int val = it->first;
            int freq = it->second;

            if(val == freq){
             ans = max(val, ans);
            }
        }

        if(ans == -1){
            return -1;
        }

        return ans;
    }
};