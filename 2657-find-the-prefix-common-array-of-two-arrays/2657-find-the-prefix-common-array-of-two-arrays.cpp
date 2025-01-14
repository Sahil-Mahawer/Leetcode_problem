class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();

        vector<int> result;

        for(int i=0;i<n;i++){
 
          int count = 0;

          for(int j=0;j<=i;j++){   // A

            for(int k=0;k<=i;k++){  //B

            if(A[j]==B[k]){
                count++;
                
            }

            }
          }

          result.push_back(count);
        }
        return result;
    }
};