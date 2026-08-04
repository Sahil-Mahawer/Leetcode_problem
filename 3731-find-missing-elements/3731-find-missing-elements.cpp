class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        vector<int> ans;

        int min_element = INT_MAX;
        int max_element = INT_MIN;

        for(int i=0; i<nums.size(); i++){

            min_element = min(min_element, nums[i]);
            max_element = max(max_element, nums[i]);
        } 

        unordered_set<int> st(begin(nums), end(nums));

        for(int i= min_element; i<=max_element; i++){

            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};