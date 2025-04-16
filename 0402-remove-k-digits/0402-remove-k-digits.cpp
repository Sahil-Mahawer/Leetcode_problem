class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string result = "";

        int n = num.size();

        if(num.size() == k){
            return "0";
        }

        for(int i=0;i<n;i++){

            while(result.size() > 0 && result.back() > num[i] && k > 0 ){
                result.pop_back();
                k--;
            }

            if(num[i]!='0' || result.size() > 0){
                result.push_back(num[i]);
            }
        }

        while(result.size() && k > 0){
            result.pop_back();
            k--;
        }

        if(result == ""){
            return "0";
        }

        return result;
    }
};