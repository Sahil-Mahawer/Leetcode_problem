class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        unordered_set<string> st(begin(folder), end(folder));

        vector<string> result;

        for(int i=0; i<folder.size(); i++){

            string curr_folder = folder[i];

            string temp_folder = curr_folder;

            bool is_subFolder = false;

            while(curr_folder != ""){  // jbb tkk curr_folder empty nhi ho jaata 

                 size_t last_position_of_slash = curr_folder.find_last_of('/');

                 curr_folder = curr_folder.substr(0,last_position_of_slash);

                 if(st.find(curr_folder) != st.end()){

                    is_subFolder = true;
                    break;
                 }
            }

            if(is_subFolder == false){

                result.push_back(temp_folder);
            }


        }

        return result;
    }
};