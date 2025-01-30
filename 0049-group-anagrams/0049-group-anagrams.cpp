class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
    int n = strs.size();

     vector<vector<string>> result;

    unordered_map< string , vector<string>> mpp;

    for(int i=0;i<n;i++)
    {

        string temp = strs[i];

        sort(temp.begin(), temp.end());

        mpp[temp].push_back(strs[i]);

    }
      
    for(auto it = mpp.begin(); it!=mpp.end(); it++){

        result.push_back(it->second);
    }


    return result;
    }
};