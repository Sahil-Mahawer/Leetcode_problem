class Solution {
public:

    void fillNeighbours(string &curr, queue<string>& que, unordered_set<string>& st)
    {

        for(int i=0; i<4; i++){

            char ch = curr[i];

            char dec = ch == '0' ? '9' : ch - 1;
            curr[i] = dec;

            if(st.find(curr) == st.end()){

                que.push(curr);
                st.insert(curr);
            }

            char inc = ch == '9' ? '0' : ch + 1;
            curr[i] = inc;

            if(st.find(curr) == st.end()){

                que.push(curr);
                st.insert(curr);
            }

            curr[i] = ch;
        }
    }


    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> st(begin(deadends), end(deadends));

        queue<string> que;
        string start = "0000";

        if(st.find(start) != st.end()){
            return -1;
        }

        int level = 0;

        que.push(start);

        while(!que.empty()){

            int n = que.size();

            while(n--){

                string curr = que.front();
                que.pop();

                if(curr == target){
                    return level;
                }

                fillNeighbours(curr, que, st);
            }

            level++;
        }

        return -1;
    }
};