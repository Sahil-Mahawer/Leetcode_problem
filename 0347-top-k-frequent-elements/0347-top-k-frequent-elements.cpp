class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;

        priority_queue<tuple<int,int>> st;

        unordered_map<int,int> freq;

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        for(auto it = freq.begin(); it!= freq.end(); it++){

            st.push({it->second, it->first});
        }

        while(k){

            auto[f,v] = st.top();

            ans.push_back(v);

            st.pop();

            k--;
        }

        return ans;
    }
};