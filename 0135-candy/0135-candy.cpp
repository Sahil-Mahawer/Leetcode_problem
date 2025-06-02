class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();

        vector<int> left_se_check(n,1);

        vector<int> right_se_check(n,1);


        for(int i=1; i<n; i++){

            if(ratings[i] > ratings[i-1]){
                left_se_check[i] =  left_se_check[i-1]+1;
            }
        }

        for(int i=n-2; i>=0; i--){

            if(ratings[i] > ratings[i+1]){
                right_se_check[i] = right_se_check[i+1]+1;
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++){

            ans += max(left_se_check[i],right_se_check[i]);
        }

        return ans;
    }
};