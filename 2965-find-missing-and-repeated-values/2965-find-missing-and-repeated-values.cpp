class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        vector<int>ans(2);

        int n = grid.size();

        unordered_map<int,int> mpp;

        int check = n*n;

       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            int value = grid[i][j];
            mpp[value]+=1;
        }
       }

       for(auto it = mpp.begin();it!=mpp.end();it++){

        int value = it->first;
        int freq = it->second;

        if(freq>1){
            ans[0] =value;  
        }
       }

       for(int i=1;i<=check;i++){

        if(mpp.find(i) == mpp.end()){
            ans[1] = i;
        }
       }

       return ans;
    }
};