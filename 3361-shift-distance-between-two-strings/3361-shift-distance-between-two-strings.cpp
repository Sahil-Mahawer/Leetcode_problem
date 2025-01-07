class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        
        long long total_cost=0;

        for(int i=0;i<s.size();i++){
        int current_index= s[i]-'a';
        int target_index = t[i]-'a';


        int next_shift_distance = (target_index - current_index +26)%26;     // a to c :- 0 to 2 => (2-0+26)%26    and +26 is done to handle negative values
        long long   next_shift_cost = 0;

        for(int j=0;j<next_shift_distance;j++){
            next_shift_cost += nextCost[(current_index+j)%26];
        }

        int previous_shift_distance = (current_index - target_index+26)%26;  // c to a :- 2 to 0 => (2-0+26)%26   and +26 is done to handle negative values
         long long  previous_shift_cost =0;

        for(int j=0;j<previous_shift_distance;j++){
              previous_shift_cost += previousCost[(current_index - j+26)%26];  // +26 is done to handle negative values
        }

        total_cost += min(next_shift_cost,previous_shift_cost);
        }
        return total_cost;
    }
};