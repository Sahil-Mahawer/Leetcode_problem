class Solution {
public:

    int n;

    bool isValid(vector<int>& nums, int mid, int p)
    {

        int i = 0;
        int countPairs=0;

        while(i < n-1){

            if(abs(nums[i] - nums[i+1]) <= mid){
                countPairs++;
                i += 2;
            }
            else{
                i++;
            }
        }

        if(countPairs >= p){
            return true;
        }

        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {

        n = nums.size();

        sort(begin(nums), end(nums));

        int result  = INT_MAX;

        int start = 0;
        int end = nums[n-1] - nums[0]; // maximum difference yhi hoskta hai .. (max element - min element)

        // hmm ye nikal rhe hai ki ye difference p pairs se possible ha ki nhi 

        while(start <= end){

            int mid = start + (end - start) / 2;

            if(isValid(nums, mid, p) == true){

                result = mid;
                end  = mid - 1;  
            }
            else{

                start = mid + 1;
            }
        }

        return result;
    }
};