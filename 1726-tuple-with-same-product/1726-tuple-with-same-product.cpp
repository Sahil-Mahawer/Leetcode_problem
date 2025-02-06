class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        unordered_map<int,int> count_product_freq;
        int n = nums.size();
        int count = 0;

        for(int i=0;i<n-1;i++){

            for(int j=i+1;j<n;j++){

                count_product_freq[nums[i]*nums[j]]++;
            }
        }


        for(auto it=count_product_freq.begin(); it!=count_product_freq.end();it++)
        {
            int freq = it->second;

            if(freq>1){
                count += 8*(freq*(freq-1))/2;
            }
        }

        return count;
    }
};