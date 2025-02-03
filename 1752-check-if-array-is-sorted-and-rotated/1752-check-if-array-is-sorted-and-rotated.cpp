class Solution {
public:
    bool check(vector<int>& nums) {

        vector<int> sorted = nums;
        int n= nums.size();

        sort(sorted.begin(), sorted.end());

        for (int rotate = 0; rotate <= n; rotate++) {
            bool is_sorted = true;
            for (int i = 0; i < n; i++) {

                if (sorted[i] != nums[(i + rotate) % n]) {
                    is_sorted = false;
                    break;
                }
            }

            if (is_sorted == true) {
                return true;
            }
        }
        return false;
    }
};