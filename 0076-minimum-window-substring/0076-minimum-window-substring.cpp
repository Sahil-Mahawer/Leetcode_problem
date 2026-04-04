class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size();

        if(t.size() > s.size()){
            return ""; // agrr t ka size bdaa hai s se .. toh hmee string kbhi milegi hee nhi 
        }

        unordered_map<char,int> mp;

        for(char &ch : t){
            mp[ch]++;
        }

        int requiredCount = t.size();
        int i=0, j=0;

        int min_window_size = INT_MAX;
        int start_i = 0;

        while(j < s.size()){

            char ch = s[j];   // taking characters of  string s 

            if(mp[ch] > 0){   // it is the character we require... it is in t string... 

               requiredCount --;   // ik character mill gya toh abb ye require nhi hai hmee     
            }

            mp[ch]--;

            while(requiredCount == 0){   // shrinking phase start

                int current_window_size = j-i+1;

                if(min_window_size > current_window_size){
                    min_window_size = current_window_size;
                    start_i = i;
                }

                mp[s[i]]++;  //increase the frequenct at i charcter .. as now it is 

                if(mp[s[i]] > 0){
                    requiredCount++;  // we want this character
                }

                i++;
            }

            j++;
        }

        return min_window_size ==  INT_MAX ? "" : s.substr(start_i, min_window_size);
    }
};