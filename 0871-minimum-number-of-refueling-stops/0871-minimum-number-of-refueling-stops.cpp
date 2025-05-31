class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        priority_queue<int> pq;

        int i = 0;

        int fuel = startFuel;

        int n = stations.size();

        int refuels=0;

        while(fuel < target){

            while(i < n && fuel >= stations[i][0]){

                pq.push(stations[i][1]);
                i++;
            }

            if(pq.empty()){
                return -1;
            }

            fuel += pq.top();
            pq.pop();

            refuels++;
        }

        return refuels;
    }
};