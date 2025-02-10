class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int n = time.size();
        long long count=0;
        unordered_map<int,int> freq;

        for(int i=0;i<n;i++){

            time[i] = time[i]%60;
            int remaining = (60-time[i])%60;
            count = count+ freq[remaining];
            freq[time[i]]++;
        }

       
        return count;
    }
};