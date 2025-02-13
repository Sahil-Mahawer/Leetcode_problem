class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> max_heap(begin(piles), end(piles));

        while(k){

            int largest = max_heap.top();
            max_heap.pop();

            int reduced_value = largest - (largest/2);
            max_heap.push(reduced_value);
            
            k--;
        }

        int total_sum = 0;

        while(!max_heap.empty()){

            total_sum += max_heap.top();
            max_heap.pop();
        }

        return total_sum;
    }
};