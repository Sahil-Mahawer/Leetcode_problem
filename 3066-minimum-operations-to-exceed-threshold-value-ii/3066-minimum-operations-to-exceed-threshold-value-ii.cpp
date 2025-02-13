class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<int , vector<int>, greater<int>> min_heap(begin(nums), end(nums));

        int operations = 0;

        while(min_heap.size()>=2 && min_heap.top()<k)
        {
            long long x = min_heap.top();
            min_heap.pop();

            long long  y = min_heap.top();
            min_heap.pop();

            long long  new_value =  (long long )min(x, y) * 2 + max(x, y);

            min_heap.push(new_value);

            operations++;
        }

        return operations;
    }
};