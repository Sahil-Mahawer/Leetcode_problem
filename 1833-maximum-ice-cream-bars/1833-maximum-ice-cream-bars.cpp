class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int count = 0; 
        int price= 0;

        sort(begin(costs), end(costs));

        for(int i=0; i<costs.size(); i++){

          price += costs[i];

          if(price <= coins){
            count++;
          } 

          else{

            break;

          }
          
        }

        return count;
    }
};