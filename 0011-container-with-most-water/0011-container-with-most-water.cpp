class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int ans=0, area , mini_height, distance;
        
        int start = 0, end = n-1;

        while(start<end){

            mini_height = min(height[start], height[end]);
            distance = end - start;
            area = mini_height*distance;
            ans = max(area,ans);

            if(height[start]<height[end]){
                start++;
            }
            else
            end--;

        }

        return ans;
    }
};