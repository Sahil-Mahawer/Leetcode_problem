class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
       int n = prices.size();
    //    int profit = 0;
    //    int max_profit = 0; 
    //    vector<int> profitInFuture(n);

    //    profitInFuture[n-1] = prices[n-1];

    //    for(int i = n-2; i>=0; i--){

    //     profitInFuture[i] = max(profitInFuture[i+1], prices[i]);
    //    }

    //    for(int i=0; i<n; i++){

    //     profit = profitInFuture[i] -  prices[i] ;

    //     max_profit = max(max_profit, profit); 
    //    }


    //     return max_profit;


    int mini = INT_MAX;
    int max_profit = 0;

    for(int i=0; i<n; i++){

        mini = min(mini, prices[i]);

        max_profit = max(max_profit, prices[i] - mini);
    }

    return max_profit;
    }
};