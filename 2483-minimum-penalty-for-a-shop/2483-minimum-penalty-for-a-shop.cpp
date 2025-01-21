class Solution {
public:
    int bestClosingTime(string customers) {
        
        int countN=0, countY=0;
        int n = customers.size(); 

        for(int i=0;i<customers.size();i++){

            if(customers[i]=='Y'){
                countY++;
            }
            else
            {
                countN++;
            }
        }

        if(countY==customers.size()){
            return customers.size();
        }

        if(countN==customers.size()){
            return 0;
        }

       
       int result = INT_MAX;
       int index = -1;

       vector<int> prefixN(n+1,0);
       prefixN[0] = 0;

       vector<int> suffixY(n+1,0);
       suffixY[n]=0;

       for(int i=1;i<=n;i++){

        if(customers[i-1]=='N'){
            prefixN[i] = prefixN[i-1]+1;
        }
        else{
            prefixN[i] = prefixN[i-1];
        }

       }

       for(int i=n-1;i>=0;i--){

        if(customers[i]=='Y'){
            suffixY[i] = suffixY[i+1]+1;
        }
        else{
            suffixY[i] = suffixY[i+1];
        }

       }

       for(int i=0;i<=n;i++){

        int total_penalty = prefixN[i] + suffixY[i];

        if( total_penalty < result){
             result = total_penalty ;
            index = i;
        }
       }

       return index;
       
    }
};