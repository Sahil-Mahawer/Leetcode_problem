class Solution {
public:

bool check(int index, int curr_sum, string s, int num)
{

    if(index == s.size()){
        return curr_sum == num; // if they both are same it will return true, otherwise false
    }

    if(curr_sum > num){
        return false;
    }

    bool possible = false;

    for(int j=index;j<=s.size();j++){
        string sub =  s.substr(index, j-index+1);

        int val = stoi(sub);

        possible = possible || check(j+1, curr_sum+val,s, num);

        if(possible == true){
            return true;
        }
    }

    return possible;

}
 
 
    int punishmentNumber(int n) {
        
        int punish = 0;

        for(int num=1;num<=n;num++){

            int sq = num*num;

            string s = to_string(sq);    // digit + '0'  :- for conversion we use this (direct logic without inbuilt)
            
            int index = 0;
            int curr_sum = 0;

            if(check(index, curr_sum, s ,num)==true){
                punish = punish+sq;
            }
        }

        return punish;

    }
};