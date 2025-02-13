class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<int> max_heap(begin(gifts), end(gifts));

        while(k){

            int largest = max_heap.top();
            max_heap.pop();

            int new_value = sqrt(largest);
            max_heap.push(new_value);

            k--;
        }

        long long  total_gifts = 0;

        while(!max_heap.empty()){
            total_gifts += max_heap.top();
            max_heap.pop();
        }

        return total_gifts;
    }
};