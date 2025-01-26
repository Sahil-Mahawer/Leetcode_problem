class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int count=0;

        for(int i=0;i<n-1;i++){
            left += nums[i];

        for(int j=i+1;j<n;j++){
            right += nums[j]; 
        }

        if(abs(left-right)%2==0){
            count++;
        }

        }

        return count;
    }
};