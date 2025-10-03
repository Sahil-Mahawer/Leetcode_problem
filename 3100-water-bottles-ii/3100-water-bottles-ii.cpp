class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        

        int empty = numBottles; // in one operation we can drink any number of full bottles to make it empty

        int drink = numBottles;  // kitni paani peeliya

        while(empty >= numExchange) {

            empty = empty - numExchange;// with this you get one full water bottle

            drink++; // and then you drink tht bottle 

            empty++; //  when you drink that bottle it becomes empty

            numExchange++;
        }

        return drink;
    }
};