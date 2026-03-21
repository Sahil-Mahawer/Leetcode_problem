class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();

        vector<int> leftMax(n);
        vector<int> rightMax(n);
        int water = 0;
        leftMax[0] = 0;
        rightMax[n-1] = 0;
        int min_height = 0;

        for(int i=1; i<n; i++){  // for left max

            leftMax[i] = max(leftMax[i-1], height[i-1]);
        } 

        for(int i=n-2; i>=0; i--){

            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }

        for(int i=0; i<n; i++){

            int min_height = min(leftMax[i], rightMax[i]);

            if(min_height - height[i] >= 0){
                water += min_height - height[i];
            }
        }

        return water;
    }
};
