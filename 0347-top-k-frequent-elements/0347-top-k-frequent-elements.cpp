class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;
        int n = nums.size();

        priority_queue<tuple<int,int>> st;
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){

            mp[nums[i]]++;
        }

        for(auto it=mp.begin(); it!=mp.end(); it++){

            st.push({it->second,it->first});
        }

        while(k--){

            auto[f,t] = st.top();
            ans.push_back(t);
            st.pop();
        }

        return ans;
    }
};