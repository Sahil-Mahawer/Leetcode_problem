class Solution {
public:
    int maxDiff(int num) {
        
        string str1 = to_string(num); // for maximum

        string str2 = to_string(num); // for minimum

        int idx = str1.find_first_not_of('9');   // this will give first index where character 9 is not present

        if( idx != string::npos){  // means we get a valid index
            
            char ch = str1[idx]; // get that character 

            replace(begin(str1), end(str1), ch, '9'); // replace all occuring of that character with '9'

        }

        // for minimum:-

       //  if(i==0)  cant put '0' .. as given we cant take leading zeros .. so put '1' if it is not equal to '1'

    //    if(i>0) ... if digit is not equal to '0' && digit != str2[0]  change digit to '0' 


        for(int i=0; i<str2.size(); i++){

            char ch = str2[i];

            if(i==0){

                if(ch != '1'){
                    replace(begin(str2), end(str2), ch, '1');
                    break;
                }
            }else if(ch != '0' && ch != str2[0]){
                replace(begin(str2), end(str2), ch, '0');
                break;
            }
            

        }

        return stoi(str1) - stoi(str2);
    }
};