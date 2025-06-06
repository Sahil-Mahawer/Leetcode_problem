class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        // pair<int, pair<int,int>>; // value, (row, col) 

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;
        int minimum , maximum = INT_MIN;

        // Initialize heap with first element from each list
        for(int i = 0; i<nums.size(); i++)
        {
            pq.push(make_pair(nums[i][0], make_pair(i,0)));
            maximum = max(maximum,nums[i][0]);

        }

        minimum = pq.top().first;
        vector<int> ans(2);

        // Best answer so far
        ans[0] = minimum;
        ans[1] = maximum;

        pair<int, pair<int,int>> temp;
        int row, col, element;

        while(pq.size() == nums.size()){

            temp = pq.top();
            pq.pop();

            element = temp.first;

            row = temp.second.first;
            col = temp.second.second;

            if(col+1 < nums[row].size()){

                pq.push(make_pair(nums[row][col+1], make_pair(row, col+1)));
                maximum = max(maximum, nums[row][col+1]);
                minimum = pq.top().first;
            }

            if(maximum - minimum < ans[1] - ans[0]){
                ans[1] = maximum;
                ans[0] = minimum;
            }
        }
        
        return ans;
    }
};