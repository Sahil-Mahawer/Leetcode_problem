class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        int n = events.size();

        sort(begin(events), end(events));

        priority_queue<int, vector<int>,  greater<int>> pq;

        int days = events[0][0];

        int i=  0;

        int count = 0;

        while(!pq.empty() || i < n){

            while(i < n && events[i][0] == days){

                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
            pq.pop(); // 1 event attended on this day 
            count++;
            }

            days++;


            while(!pq.empty() && pq.top() < days){

                pq.pop();
            }

        }

        return count;

    }
};