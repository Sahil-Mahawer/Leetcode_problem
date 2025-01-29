class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int check2 = -1;
        string result = "";

        for (int i = 0; i < n; i++) {
            long long digit = 0;  // Initialize digit outside inner loop

            for (int j = i; j < n; j++) {
                digit = digit * 10 + (num[j] - '0');  // Convert substring to number

                if (digit % 2 != 0) {  // If odd, check for max
                    if (digit > check2) {
                        check2 = digit;
                        result = num.substr(i, j - i + 1);  // Store the substring
                    }
                }
            }
        }

        return result;
    }
};
