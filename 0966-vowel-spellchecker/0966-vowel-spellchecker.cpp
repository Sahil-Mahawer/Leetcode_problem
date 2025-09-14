class Solution {
public:

unordered_set<string> exact_set;
unordered_map<string,string> lower_mp;
unordered_map<string,string> vowel_mp;


string toLower(string &s){

    string result = s;

    for(int i=0; i<result.size(); i++){

       result[i]  = tolower(result[i]);
    }

    return result;

}


string toReplace(string &s){

    string result = s;

    for(int i=0; i<result.size(); i++){

        

        if(result[i] == 'a'|| result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u'){

            result[i] = '*';
        }
    }

    return result;
}


    string checkForMatch(string &query){

        if(exact_set.count(query)){
            return query;
        }

        // case-sensitive issue
        string lowercase = toLower(query);
        if(lower_mp.count(lowercase)){
            return lower_mp[lowercase];
        }

        string vowelcase = toReplace(lowercase);
        if(vowel_mp.count(vowelcase)){
            return vowel_mp[vowelcase];
        }


        return "";
    }


    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

            exact_set.clear();
            lower_mp.clear();
            vowel_mp.clear();


            for(int i=0; i<wordlist.size(); i++){

                string str = wordlist[i];

                exact_set.insert(str);  // for exact match 

                string lowerCase = toLower(str);    // for case-sensitive issues 
                if(lower_mp.find(lowerCase) == lower_mp.end()){

                    lower_mp[lowerCase] = str;
                }


                string vowelCase = toReplace(lowerCase);   // for vowel issue 
                if(vowel_mp.find(vowelCase) == vowel_mp.end()){

                    vowel_mp[vowelCase] = str;
                }
            }

            vector<string> result;

            for(int i=0; i<queries.size(); i++){

                result.push_back(checkForMatch(queries[i]));
            }

            return result;
    }
};