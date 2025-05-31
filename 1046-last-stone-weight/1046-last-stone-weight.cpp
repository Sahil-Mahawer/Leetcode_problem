class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq(begin(stones), end(stones));

    

        while(pq.size()>1){

            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            int diff = first - second;

            pq.push(diff);
        }

        return pq.top();
    }
};