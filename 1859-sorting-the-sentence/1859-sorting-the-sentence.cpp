class Solution {
public:
    string sortSentence(string s) {
        
        vector<string> ans(10);
        string temp;

        int count=0, index=0;

        while(index<s.size()){

            if(s[index]== ' '){
            
            int pos = temp[temp.size()-1] - '0';
            temp.pop_back();

            ans[pos] = temp;
            temp.clear();
            count++;

            }
            else{
                temp = temp+s[index];
            }
            index++;
        }
         int pos = temp[temp.size()-1] - '0';  // for last word .. as loop get terminted due to index becomes greater than size of sentence.
            temp.pop_back();

            ans[pos] = temp;
            temp.clear();
            count++;

        for(int i=1;i<=count;i++){

            temp = temp+ans[i];
           
           if(i!=count)
            temp += ' ';

        }

        return temp;
    }
};