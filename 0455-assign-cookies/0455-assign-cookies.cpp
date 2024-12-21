class Solution {
public:
    int findContentChildren(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i=0,j=0;
        int matching = 0;

        while(i<players.size() && j<trainers.size()){

            if(players[i]<=trainers[j]){
                i++;
                j++;
                matching++;
            }
            else{
                j++;
            }
        }

        return matching;
    }
};