class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<vector<int>> merge;

        sort(intervals.begin(), intervals.end()); // sort intervals by start time

        for(int i=0;i<n;i++){

            if(merge.empty()){
                merge.push_back(intervals[i]); 
            }

            else{
                vector <int>& last_interval = merge.back();

                if(intervals[i][0]<=last_interval[1]){      // comaparing end time of last interval with the start time of current interval, if start time of current interval is less than the end time of last inserted interval .. then they can overlap .. update the end time of previously inserted interval.

                    last_interval[1] = max(last_interval[1], intervals[i][1]);  // here we have update the end time of previously inserted interval .. hence overlaping done 
                }

                else{
                    merge.push_back(intervals[i]); // start time of current interval is not less ( means it is more ) than the end time of previously inserted interval  eg:- {1,4} {6,8} then in this case add new interval ... means add{6,8} // bacause it cant be overlapped
                }
            }
        }
        return merge;
    }
};