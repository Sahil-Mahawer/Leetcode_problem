class Solution {
public:
vector<vector<int>> result;

void solve(int idx , vector<int>& candidates,int target,   vector<int> &temp)
{

    if(idx == candidates.size())
    {
        if(target == 0)
        {
            result.push_back(temp);
        }

        return;
    }

    if(candidates[idx]<=target){

        temp.push_back(candidates[idx]);

        solve(idx , candidates , target - candidates[idx], temp);

        temp.pop_back();
    }


    solve(idx+1, candidates, target, temp);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> temp;

        solve(0, candidates, target, temp);  // 0:- index

        return result;
    }
};