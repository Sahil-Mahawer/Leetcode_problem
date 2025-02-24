class Solution {
public:
vector<vector<int>> result;

    void solve(vector<int>& candidates, vector<int> &current, int idx, int target)
    {
             
             if(idx == candidates.size()){

                if(target == 0){
                    result.push_back(current);
                }
                return;
             }

             if(candidates[idx]<=target){

                current.push_back(candidates[idx]);
                solve(candidates, current, idx+1, target - candidates[idx]);
                current.pop_back();
             }

             while(idx+1 < candidates.size() && candidates[idx] == candidates[idx+1]){
                idx++;
             }


             solve(candidates, current, idx+1, target);




    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(begin(candidates), end(candidates));
        vector<int> current;
        int idx = 0;

        solve(candidates, current, idx,  target);

        return result;
    }
};