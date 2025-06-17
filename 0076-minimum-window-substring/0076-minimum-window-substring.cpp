class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s==t){
            return t;
        }

        if(s.size()<t.size()){
            return "";
        }


        int mini_length = INT_MAX;

        int start = 0 , end =0 , n = s.size();

        unordered_map<char, int> t_map;

        for(int i=0;i<t.size();i++)
        {
            t_map[t[i]]++;
        }

        int required_character_count  =  t_map.size();

        int current_window_character = 0;
        unordered_map<char,int> window_map;
        int start_index = 0; 

        while(end < s.size()){
            char c = s[end]; 
            if(t_map.find(c) != t_map.end()) // means agr current character "t_freq" vaale map mai present hai
            {
                window_map[c]++;
            

            if(window_map[c] == t_map[c] ){
                current_window_character++;
            }
            }

            while(current_window_character == required_character_count ){

                if(end-start+1 < mini_length){
                    mini_length = end-start+1;
                    start_index = start;
                }


                char left = s[start];
                if(t_map.find(left)!=t_map.end()){

                    window_map[left]--;

                    if(window_map[left] < t_map[left]){
                        current_window_character--;
                    }
                }
                start++;
            }

            end++;
        }

        return mini_length == INT_MAX ? "" : s.substr(start_index, mini_length);
    }
};