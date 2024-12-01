class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
      
        int mini_height , water = 0;
        vector<int> left_max(n) , right_max(n);

        left_max[0] = height[0];

        for(int i =1;i<n;i++){
            left_max[i] = max(left_max[i-1], height[i]);
        }

        right_max[n-1] = height[n-1];

        for(int i=n-2;i>=0;i--){

            right_max[i] = max(height[i], right_max[i+1]);
        }

        for(int i=0;i<n;i++){
            mini_height = min(right_max[i], left_max[i]);

            if(mini_height-height[i]>=0){
                water = water + mini_height-height[i];
            }
        }

        return water;

    }
};
