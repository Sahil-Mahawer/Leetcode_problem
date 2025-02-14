class Solution {
public:

void permute(vector<int>& nums, int idx , vector<vector<int>> &ans){

if(idx == nums.size()){
    ans.push_back(nums);
    return; 
}

for(int i=idx;i<nums.size();i++){

    swap(nums[idx],nums[i]);
    permute(nums , idx+1 , ans);

    // Backtrack
    swap(nums[idx],nums[i]);
}

}



    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;

       int idx = 0;

       permute(nums , idx , ans);

       return ans; 
    }
};