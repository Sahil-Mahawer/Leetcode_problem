class Solution {
public:
vector<vector<int>> result;

void solve (int num, int k, int target , vector<int> &temp)
{

        if(k==0){
            if(target ==0){
                result.push_back(temp);
            }
            return;
        }

        if(num>9){
            return;
        }

        if(num <= target){
            temp.push_back(num);
            solve(num+1,k-1, target - num , temp );
            temp.pop_back();
        }

        solve(num+1, k , target, temp);

}
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> temp;
        int num = 1;

        solve(num, k , n, temp);

        return result;

    }
};