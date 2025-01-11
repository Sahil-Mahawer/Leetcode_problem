class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        vector<int> not_grumpy_index;
        int n  = grumpy.size();
        int sum =0;

        for(int i=0;i<n;i++){

            if(grumpy[i]==0){
                not_grumpy_index.push_back(i);
            }
        }

        for(int i=0;i<not_grumpy_index.size();i++){
            sum+= customers[not_grumpy_index[i]];
        }

        int start = 0, end = 0, sum2=0, count=0, totalsum=-1;

        while(end<n){

         count++;   // minutes started 

         if(grumpy[end]==1 && customers[end]!=0){
            sum2 += customers[end]; 
         }

         while(count==minutes){
            totalsum = max(totalsum, sum2);

            if(grumpy[start]==1){
            sum2 -= customers[start];
            }
            
            count--;

            start++;
         }

         end++;

        }

        return totalsum+sum;
    }
};