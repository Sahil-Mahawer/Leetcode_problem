class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {

        int n = arr.size();
        vector<string> result(n);

        unordered_map<string, int> substr_freq;

        for (int k = 0; k < n; k++) {

            string str = arr[k];

                unordered_set<string>
                    seen;

            for (int i = 0; i < str.size(); i++) {

                for (int j = i + 1; j <= str.size(); j++) {

                    string substr = str.substr(i, j - i);

                    if (seen.find(substr) == seen.end()) {
                        substr_freq[substr]++;
                        seen.insert(substr);
                    }
                }
            }
        }

        for (int k = 0; k < n; k++) {

            string str = arr[k];

            string shortest = "";

            for (int i = 0; i < str.size(); i++) {

                for (int j = i + 1; j <= str.size(); j++) {

                    string substr = str.substr(i, j - i);

                    if(substr_freq[substr]==1 && (shortest == "" || substr.size()<shortest.size() || (shortest.size() == substr.size() && substr < shortest))){
                        shortest = substr;
                    }
                }
            }
            result[k] = shortest;
        }

        return result;
    }
};