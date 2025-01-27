class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mpp;
        
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }

        vector<pair<char,int>> freq_vec (mpp.begin(), mpp.end());


        auto lambda = [&] (pair<char, int> &p1 , pair<char, int> &p2){
            return p1.second > p2.second;
        };
        sort(freq_vec.begin(), freq_vec.end(),lambda);
        
        string result = "";
        for(int i=0;i<freq_vec.size();i++){
            char ch = freq_vec[i].first;
            int freq = freq_vec[i].second;
            result += string(freq , ch );
        }
    return result;
    }
};