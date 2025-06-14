class Solution {
public:
    int minMaxDifference(int num) {
        
        string str1 =to_string(num);  //for maximum  ... search from left where digit is not 9 when we got the first digit which is not 9 make it 9 and all the occurences of digit also make 9

        string str2 = to_string(num);  // for minimum  ... convert first digit to 0 ..

        int idx = str1.find_first_not_of('9');

        if(idx != string::npos){
            char ch =  str1[idx];

            replace(begin(str1),end(str1), ch , '9');
        }

        char ch = str2[0];

        replace(begin(str2), end(str2), ch, '0');


        return stoi(str1) - stoi(str2);
    }
};