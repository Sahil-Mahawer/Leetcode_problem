class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        
        int n = nums.size();

        int left = *min_element(begin(nums), end(nums));
        int right = *max_element(begin(nums), end(nums));

        int result = 0;

        while(left <= right){

            int mid = left+(right-left)/2;

            int house = 0;

            for(int i=0;i<n;i++){

                if(nums[i] <= mid){
                    house++;
                    i++;
                }
            }

            if(house >= k){
                result = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return result;
    }
};