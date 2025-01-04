// class Solution {
// public:
//     string sortVowels(string s) {
        
//         // vector<int> upper(26,0), lower(26,0);
//         string vowel;

//         for(int i=0;i<s.size();i++){

//             // if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'){
//             //     lower[s[i]-'a']++;
//             //     s[i] = '#';
//             // }

//             // else if(s[i]=='A'|| s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U'){
//             //     upper[s[i]-'A']++;
//             //     s[i]='#';
//             // }

//               if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u' || s[i]=='A'|| s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U' ){
//                 vowel = vowel+s[i];
//                 s[i] = '#';
//               }
//         }

//         sort(vowel.begin(), vowel.end());

//         // for(int i=0;i<26;i++){

//         //         char c = 'A'+i;
 
//         //         while(upper[i]){   // pehle uppper case aayga kyuki uski ASCI value kmm hoti hai 
//         //         vowel = vowel+c;
//         //         upper[i]--;
//         //     }
//         // }
//         //      for(int i=0;i<26;i++){

//         //         char c = 'a'+i;

//         //         while(lower[i]){
//         //         vowel = vowel+c;
//         //         lower[i]--;
//         //     }

//         //}

//         int first = 0, second = 0;   // first is pointing to string s and second is pointing to vowel

//         while(second<vowel.size()){

//             if(s[first]=='#'){
//                 s[first] = vowel[second];
//                 second++; 
//             }
//             first++;
//         }
//         return s;
//     }
    
// };

class Solution {
public:
    string sortVowels(string s) {
        vector<int> upper(26, 0), lower(26, 0);
        vector<char> vowels; // Using vector to store vowels

        // Step 1: Collect vowels and replace them with '#'
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                lower[s[i] - 'a']++;
                vowels.push_back(s[i]); // Collect vowel in vector
                s[i] = '#'; // Mark vowel positions with '#'
            } else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                upper[s[i] - 'A']++;
                vowels.push_back(s[i]); // Collect vowel in vector
                s[i] = '#'; // Mark vowel positions with '#'
            }
        }

        // Step 2: Sort the collected vowels
        sort(vowels.begin(), vowels.end());

        // Step 3: Replace '#' in the string with sorted vowels
        int first = 0, second = 0; // first is pointing to string s and second is pointing to vowels vector
        while (second < vowels.size()) {
            if (s[first] == '#') {
                s[first] = vowels[second];
                second++;
            }
            first++;
        }

        return s;
    }
};
