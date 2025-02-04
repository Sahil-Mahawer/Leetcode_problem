class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {

        int n = security.size();
        vector<int> result;

        if(time == 0){
            for(int i=0;i<n;i++){
                result.push_back(i);
            }
            return result;
        }

        vector<int> left_inc(n,0);

        left_inc[0] = 0; // as there is no element in left

        for(int i=1;i<n;i++){

            if(security[i]<=security[i-1]){
                left_inc[i] = left_inc[i-1]+1;
            }
            else{
                left_inc[i]=0;
            }
        }

        vector<int> right_inc(n,0);

        right_inc[n-1] =0;

        for(int i=n-2;i>=0;i--){

            if(security[i] <= security[i+1]){
                right_inc[i] = right_inc[i+1] + 1; 
            }
            else{
                right_inc[i] = 0; 
            }
        } 


        for(int i=0;i<n;i++){

            if(left_inc[i]>=time && right_inc[i]>= time){
                result.push_back(i);
            }
        }


        return result;
    }
};