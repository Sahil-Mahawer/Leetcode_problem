class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        

        unordered_set<int> sadusers;

        for(auto &friends : friendships){

            int u = friends[0] - 1;
            int v = friends[1] - 1;

            unordered_set<int> langSet(languages[u].begin(), languages[u].end());

            bool canTalk = false;

            for(int lang : languages[v]){

                if(langSet.count(lang)){

                    canTalk = true;
                    break;
                }
            }

            if(canTalk == false){

                sadusers.insert(u);
                sadusers.insert(v);
            }
        }

        vector<int> language(n+1,0);
        int most_known_lang = 0;


        for(int user : sadusers){

            for(int lang : languages[user]){

                language[lang]++;
                most_known_lang = max(most_known_lang, language[lang]);
            }
        }

        return sadusers.size() - most_known_lang;
    }
};