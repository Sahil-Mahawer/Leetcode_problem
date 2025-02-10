class Solution {
public:
    long long countCompleteDayPairs(vector<int>& time) {
         int n = time.size();
        long long count=0;
        unordered_map<int,int> freq;

        for(int i=0;i<n;i++){

            time[i] = time[i]%24;
        }

        for(int i=0;i<n;i++){

            int remaining = (24-time[i])%24;
            count = count+ freq[remaining];
            freq[time[i]]++;
        }
        return count;

    }
};