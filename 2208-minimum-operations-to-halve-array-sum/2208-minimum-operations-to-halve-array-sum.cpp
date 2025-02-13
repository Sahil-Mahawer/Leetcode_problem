class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        priority_queue<double> max_heap(begin(nums), end(nums));

        double total_sum = accumulate(begin(nums), end(nums),0.0);

        double reduced_sum =0;
        
        int operations=0;

        double target = total_sum/2;

        while(total_sum - reduced_sum > target){
            double largest = max_heap.top();
            max_heap.pop();

            double reduced_value = largest/2;
            reduced_sum += reduced_value;

            max_heap.push(reduced_value);

            operations++;
        }

        return operations;
    }
};