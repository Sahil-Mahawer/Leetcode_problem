class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        
        
        int count = INT_MIN; 

        unordered_set<int> mp(begin(arr), end(arr));

        for(int i=0;i<arr.size()-1;i++){

            for(int j = i+1; j<arr.size();j++){

                int a = arr[i], b = arr[j];
                int sp = 2;

                while(mp.count(a+b)){

                    int next = a+b;
                    a=b;
                    b=next;
                    sp++;
                }

                count = max(sp,count);
                
            }

        }

        if(count<3){
            count = 0;
            return count;
        }

        return count;
    }
};