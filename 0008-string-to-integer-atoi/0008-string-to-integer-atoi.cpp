class Solution {
public:
    int myAtoi(string s) {

     
        int n = s.size();
        int sign = 1;
        long long nums = 0;

        int index = 0;

        while(index < n && s[index]==' '){
            index++;
        }

        if(index<n && (s[index]=='-'  || s[index]=='+')){
            
            if(s[index]=='-'){
                sign = -1;
            }
            index++;
        }
        

        while(index<n && isdigit(s[index]) ){

            nums = nums*10 + (s[index]-'0');

            if(nums*sign < INT_MIN) return INT_MIN;
            if(nums*sign > INT_MAX) return INT_MAX;

            index++;
        }

        return nums*sign;


        
    }
};