class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();

        int total_gas = 0;
        int total_cost = 0;
        int travel = 0;
        int index=0;


        for(int i=0;i<n;i++){
             total_gas += gas[i]; 
        }

         for(int i=0;i<n;i++){
             total_cost += cost[i]; 
        }

        if(total_gas < total_cost){
            return -1;
        }
        
        for(int i=0;i<n;i++){

            travel += gas[i]-cost[i];

            if(travel<0){
                travel=0;
                index = i+1;
            } 
        }
        return index;
    }
};