class Solution {
public:
    
    // int ncr(int n, int r){
    //      long long  res =1;

    //      for(int i=0;i<r;i++){
    //         res = res*(n-i);
    //         res = res/(i+1);
    //      }
    //      return  (int)res;
    // }
    vector<int> getRow(int rowIndex) {
        // rowIndex = rowIndex+1;
        // // int i=0;
        // vector<int> ans(rowIndex);
        // for(int c=0;c<rowIndex;c++){
        //     ans[c]= ncr(rowIndex-1 , c);
            
            
        // }
        
        // return ans;
        rowIndex = rowIndex+1;
        long long ans =1;
        vector<int>ansrow;
        ansrow.push_back(1);

        for(int col=1;col<rowIndex;col++){
            ans = ans*(rowIndex-col);
            ans = ans/col;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
    

};