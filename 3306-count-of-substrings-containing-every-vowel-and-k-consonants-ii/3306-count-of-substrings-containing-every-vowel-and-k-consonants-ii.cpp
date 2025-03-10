class Solution {
public:

bool is_vowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i'|| ch == 'o'|| ch == 'u'){
        return true;
    }
    return false;
}

    long long countOfSubstrings(string word, int k) {
         int n = word.size();

        unordered_map<char, int> mp;  // to store the count of vowels

        vector<int> next_const(n);
        int last_consonant_idx = n;

        for(int i=n-1;i>=0;i--){

            next_const[i] = last_consonant_idx;

            if(is_vowel(word[i]) == false){
                last_consonant_idx = i;
            }
        }

        int i = 0, j=0;
        long long count = 0;
        int consonant = 0;

        while(j<n){

            char ch = word[j];

            if(is_vowel(ch)){
                mp[ch]++;
            }
            else{
                consonant++;
            }


            // consonant count must be equal to k
            while(consonant > k){

                char ch = word[i];

                if(is_vowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }
                else{
                    consonant--;
                }
                i++;
            }

            while( mp.size() == 5 && consonant == k){  // valid window
                
                count += next_const[j] - j;

                char ch = word[i];

                if(is_vowel(ch)){
                    mp[ch]--;

                    if(mp[ch]==0){
                        mp.erase(ch);
                    }
                }
                else{
                    consonant--;
                }
                i++; 
            }

            j++;
        }

        return count;
    }
};