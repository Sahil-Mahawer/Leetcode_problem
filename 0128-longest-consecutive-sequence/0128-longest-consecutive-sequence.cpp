class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Better Approach 
    //     int n = nums.size();
    //     int count = 1, longest = 1;

    //     sort(nums.begin(), nums.end());
    //     for(int i=0; i<n-1; i++){

    //         if(nums[i] == nums[i+1]) continue;

    //         if(nums[i+1] - nums[i] == 1){

    //             count++;
    //         }
    //         else{

    //             count = 1;
    //         }

    //         longest = max(count,longest);
    //     }

    //     return longest;

    // }


    // Optimal Approach

unordered_set<int> st(begin(nums), end(nums));
        int ans = 0;

        for(auto it : st){

            if(st.find(it - 1) == st.end()){   // start of sequence

                int count = 1;
                int curr = it;

                while(st.find(curr + 1) != st.end()){
                    count++;
                    curr++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }

};