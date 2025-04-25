class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        priority_queue<pair<int,int>> maxHeap;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        int i = 0, j = 0;

        int n = nums.size();

        int max_length = INT_MIN;

        while(j<n){

            maxHeap.push({nums[j],j});
            minHeap.push({nums[j],j});

            while(maxHeap.top().first - minHeap.top().first > limit){
                 i = min(maxHeap.top().second, minHeap.top().second)+1;

                 while(maxHeap.top().second < i){
                    maxHeap.pop();
                 }

                while(minHeap.top().second < i){
                    minHeap.pop();
                 }  
      
            }
            max_length = max(max_length, j-i+1);
            j++;
        }

        return max_length;

    }
};