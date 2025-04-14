class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int,int> mpp;

        vector<int> ans(nums1.size());

        for(int i=0;i<nums2.size();i++){

            while(!st.empty() && nums2[st.top()] < nums2[i]){
                mpp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            mpp[nums2[st.top()]] = -1;
            st.pop();
        }

        for(int i=0;i<nums1.size();i++){
            ans[i] = mpp[nums1[i]];
        }

        return ans;
    }
};