class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        int count=0;
        if (k <= 1) return 0;
        for(int i=0;i<arr.size();i++){
            
            int product = 1;
            

            for(int j=i;j<arr.size();j++){

                product = product*arr[j];

                if(product<k){
                 count++;
                }
                else{
                    break;
                }
            }
        }

        return count;
    }
};