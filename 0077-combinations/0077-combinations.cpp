class Solution {
public:
vector<vector<int>> ans;

void solve(int n, int k, vector<int> &temp){

    if(temp.size() == k){
        ans.push_back(temp);
        return;
    }

    for(int i=1;i<=n;i++){

        if(!temp.empty() && temp.back()>=i){
            continue;
        }

        temp.push_back(i);

        solve(n,k,temp);

        temp.pop_back();

    }
}
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> temp;
        solve(n,k, temp);

        return ans;
    }
};