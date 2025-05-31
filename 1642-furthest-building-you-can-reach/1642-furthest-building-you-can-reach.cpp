class Solution {
public:
    int furthestBuilding(vector<int>& heights, int total_bricks, int ladders) {
        
        priority_queue<int> pq;

        int i=0;
        
        for (; i < heights.size() - 1; i++) {

            if (heights[i + 1] <= heights[i]) {
                continue;
            }

            int required_bricks = heights[i + 1] - heights[i];

            if (total_bricks >= required_bricks) {
                total_bricks -= required_bricks;
                pq.push(required_bricks);
            }

            else if (ladders > 0) {

                if (!pq.empty()) {

                    int maxUsed_past_brick = pq.top();

                    if (maxUsed_past_brick > required_bricks) {
                        pq.pop();
                        total_bricks += maxUsed_past_brick;
                        total_bricks -= required_bricks;
                        pq.push(required_bricks);
                        ladders--;  // use ladder for the past maxUsed brick
                    } else {
                        ladders--;  // use ladder for current step
                    }

                } else {
                    ladders--;  // use ladder directly if no previous brick used
                }

            }

            else {
                break;
            }
        }

        return i;
    }
};
