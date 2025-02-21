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

    current.push_back('0');   // do
    if(result == ""){
        solve(current,idx+1);  // explore
    }
    current.pop_back();   // undo


    current.push_back('1'); // do
    if(result == ""){
        solve(current,idx+1); // explore
    }
    current.pop_back();   // undo

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