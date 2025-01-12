class Solution {
public:
    int countPairs(vector<int>& nums) {
        int res = 0;
        map<int, int> mpp;
        for (auto n : nums) {
            mpp[n]++;
            res += mpp[n] - 1;
            string s = to_string(n);
            string s1 = "000000";
            s = s1.substr(0, 7 - s.size()) + s;
            for (int i = 0; i < s.size(); ++i) {
                for (int j = i + 1; j < s.size(); ++j) {
                    swap(s[i], s[j]);
                    int temp = stoi(s);
                    if (temp != n)
                        res += mpp[temp];
                    swap(s[i], s[j]);
                }
            }
        }
        return res;
    }
};