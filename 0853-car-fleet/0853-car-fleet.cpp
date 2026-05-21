class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, double>> cars;

        for(int i=0; i<position.size(); i++){

            double time  = (double)(target - position[i]) / speed[i];

            cars.push_back({position[i], time});
        }

        sort(begin(cars), end(cars));

        int fleet =0;
        double prevTime = 0; 

        for(int i= cars.size()-1; i>=0; i--){

                double currTime = cars[i].second;

                if(prevTime < currTime ){
                    fleet++;
                    prevTime = currTime;
                }
        }

        return fleet; 
    }
};