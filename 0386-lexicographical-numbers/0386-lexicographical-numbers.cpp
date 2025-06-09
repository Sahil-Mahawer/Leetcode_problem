class Solution {
public:

void solve(int current_num, int n, vector<int> &result)
{

    if(current_num > n){
        return;
    }

    result.push_back(current_num);

    // noew explore 
    for(int append=0; append<=9; append++){
        
        int new_num = (current_num*10) + append;

        if(new_num > n){
            return;
        }

        solve(new_num, n, result);
    }
}
    vector<int> lexicalOrder(int n) {
        
        vector<int> result;

        for(int start=1; start<=9; start++){

            solve(start, n, result);
        }

        return result;
    }
};