class Solution {
public:
    int maxScore(vector<int>& cardpoints, int k) {
        
        int leftsum=0, rightsum=0, maxsum=0;

        int n = cardpoints.size();

        for(int i=0;i<k;i++){
            leftsum+=cardpoints[i];
        }
        maxsum = leftsum;
         int right_index = n-1;

        for(int i=k-1;i>=0;i--){
            leftsum = leftsum - cardpoints[i];
            rightsum = rightsum+ cardpoints[right_index];
            right_index--;

            maxsum = max(maxsum, leftsum+rightsum);
        }

        return maxsum;
    }
};