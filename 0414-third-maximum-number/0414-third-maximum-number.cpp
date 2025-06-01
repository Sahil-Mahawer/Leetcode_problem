class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        unordered_set<int> st;

        priority_queue<int> pq;

        for(int i=0;i<nums.size();i++){

            st.insert(nums[i]);
        }

        for(auto it = st.begin(); it!= st.end(); it++){

            pq.push(*it);
        }


        if(pq.size()< 3){
            return pq.top();
        }

        pq.pop();
        pq.pop();

        return pq.top();

    }
};