class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        
        vector<int> result;

        int sum_A = accumulate(begin(aliceSizes), end(aliceSizes),0);
        int sum_B = accumulate(begin(bobSizes), end(bobSizes),0);
        
        int n = aliceSizes.size();
        int m = bobSizes.size();

        for(int i = n-1; i>=0; i--){
            for(int j = m-1;j>=0;j--){

                int diff = aliceSizes[i] - bobSizes[j];

                if(sum_A - diff == sum_B + diff){
                    result.push_back(aliceSizes[i]);
                    result.push_back(bobSizes[j]);
                    return result;
                }
            }
        }

        return result;
    
    }
};