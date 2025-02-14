class Solution {
public:

void permute(vector<int>& nums, int idx , vector<vector<int>> &ans){

    vector<bool> use(21,0);

    if(idx == nums.size()){
    ans.push_back(nums);
    return; 
    }



    for(int i=idx;i<nums.size();i++){
    
     if(use[nums[i]+10] == 0){ // not used
    swap(nums[idx],nums[i]);
    permute(nums , idx+1 , ans);

    // Backtrack
    swap(nums[idx],nums[i]);
    use[nums[i]+10] = 1;
    }
    }

}



    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>> ans;

       int idx = 0;

       permute(nums , idx , ans);

       return ans; 
    }
};