class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
      int n = prices.size();
        long long  mini = INT_MAX, maxi=INT_MIN, ans = 0;
        int index=-1;
      for(int i=0;i<n;i++){
         
         if(mini>prices[i]){
         mini = prices[i];
         index= i;
         }
        }

         for(int j=index+1;j<n;j++){
            
            maxi = max(maxi, static_cast<long long>(prices[j]));
         }
         if(maxi>mini){
         ans = maxi-mini;
         }

         return static_cast<int>(ans);
      }
    
};