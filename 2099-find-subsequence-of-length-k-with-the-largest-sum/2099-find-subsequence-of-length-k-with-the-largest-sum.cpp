class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        vector<pair<int,int>> withIndex;

        int n = nums.size();

        // pair values with its index
        for(int i=0; i<n; i++){

            withIndex.push_back({nums[i],i});
        }

        // sort in descending order
        sort(withIndex.begin(), withIndex.end(),[](auto &a, auto &b)
            {
                return a.first > b.first;
            });


       // take top k elements
       vector<pair<int,int>> topk;
       for(int i=0;i<k;i++){
        topk.push_back(withIndex[i]);
       }

       //now sort by original index to maintain the order
       sort(topk.begin(), topk.end(), [](auto&a, auto&b)
            {
                return a.second < b. second;
            });

        vector<int> result;


        // now store the final answer in vector
        for(int i=0; i<topk.size(); i++){

            result.push_back(topk[i].first);
        }

        return result;
    }
};