class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> ans(2);
        int n = numbers.size();

        for (int i = 0; i < n-1; i++) {

            int find = target - numbers[i];
            
            int start = i+1;
            int end = n-1;

            while(start <= end){

                int mid = start + (end-start)/2;

                if(numbers[mid] == find){

                    ans[0] = i+1;
                    ans[1] = mid+1;
                    return ans;
                }

                else if(numbers[mid] > find){
                    end = mid-1;
                }
                else{

                    start = mid+1;
                }
            }

        }

        return ans;
    }
};