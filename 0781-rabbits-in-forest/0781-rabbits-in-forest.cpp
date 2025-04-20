class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        int n = answers.size();

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){

            mp[answers[i]]++;
        }

        int total = 0;

        for(auto it = mp.begin(); it!=mp.end(); it++){

            int x = it->first;  // answer

            int count = it->second; // kitne logo ne x answer kiya 

            int groupSize = (x+1);
            int group = ceil((double) count/groupSize);

            total += group * (x+1);
        }
        return total;
    }
};