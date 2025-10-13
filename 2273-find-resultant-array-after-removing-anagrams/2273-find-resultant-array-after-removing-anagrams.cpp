class Solution {
public:

bool checkAnagram(string s1, string s2){

    sort(begin(s1), end(s1));
    sort(begin(s2), end(s2));

    if(s1 == s2){
        return true;
    }

    return false;
}
    vector<string> removeAnagrams(vector<string>& words) {

      vector<string> result;

      int n = words.size();

      result.push_back(words[0]);

      for(int i=1; i<n; i++){

        if( !checkAnagram(words[i], result.back())){

            result.push_back(words[i]);
        }
      }  


      return result;
    }
};