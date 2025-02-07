class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        int n = queries.size();

        vector<int> result;

        unordered_map<int , int> colormp;  // color -> count
        vector<int> ballarr(limit+1 , -1);

        for(int i=0;i<n;i++){

            int ball = queries[i][0];
            int color = queries[i][1];

            if(ballarr[ball]!=-1){

                int prev_color = ballarr[ball];
                colormp[prev_color]--;

                if(colormp[prev_color]==0){
                    colormp.erase(prev_color);
                }
            }

            ballarr[ball] = color;
            colormp[color]++;

            result.push_back(colormp.size()); 
        }

        return result;

    }
};