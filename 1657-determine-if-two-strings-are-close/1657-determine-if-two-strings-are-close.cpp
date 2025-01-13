class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size()){
            return false;
        }

        unordered_map<char,int> freq1;
        unordered_map<char,int> freq2;

        for(int i=0;i<word1.size();i++){

            freq1[word1[i]]++;
        }

          for(int i=0;i<word2.size();i++){

            freq2[word2[i]]++;
        }

        unordered_set<char> unique1;
        unordered_set<char> unique2;

        for(int i=0;i<word1.size();i++){

            unique1.insert(word1[i]);
        }

        for(int i=0;i<word2.size();i++){

            unique2.insert(word2[i]);
        }

        if(unique1 != unique2){
            return false;
        }


        vector<int> freqvalues1;
        vector<int> freqvalues2;

        for(auto it=freq1.begin();it!=freq1.end();it++){

            freqvalues1.push_back(it->second);
        }

         for(auto it=freq2.begin();it!=freq2.end();it++){

            freqvalues2.push_back(it->second);
        }


        sort(freqvalues1.begin(), freqvalues1.end());
        sort(freqvalues2.begin(), freqvalues2.end());

        if(freqvalues1== freqvalues2){
            return true; 
        }
        else{
            return false;
        }


    }
};