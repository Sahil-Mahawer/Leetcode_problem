class Solution {
public:
unordered_set<string> mp;
int n;
string result = "";

void solve(string &current , int idx){

    if(idx == n){
       if( mp.find(current) == mp.end()){
        result = current;
       }
       return;
    }

    current.push_back('0');
    if(result == ""){
        solve(current,idx+1);
    }
    current.pop_back();

    current.push_back('1');
    if(result == ""){
        solve(current,idx+1);
    }
    current.pop_back();
}
    string findDifferentBinaryString(vector<string>& nums) {
        
         n = nums.size();

         for(int i=0;i<n;i++){
            mp.insert(nums[i]);
         }

         string current  = "";

         solve(current , 0);

        return result;
    }
};