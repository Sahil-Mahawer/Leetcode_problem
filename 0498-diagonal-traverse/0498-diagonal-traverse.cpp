class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        map<int, vector<int>> mp;

        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){

                mp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> result;

        bool flip = true;

        for(auto it = mp.begin(); it!= mp.end(); it++){

            if(flip){

                reverse(it->second.begin(), it->second.end());
            }

            for(int k = 0; k<it->second.size(); k++){

                result.push_back(it->second[k]);
            }

            flip = !flip;
        }

        return result;
    }
};