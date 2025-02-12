class Solution {
public:

void subsequence(vector<int> nums, int index , int n , vector<int> temp , vector<vector<int>> &ans)
{

    // Base condition
    if(index == n){
       
        ans.push_back(temp);
        return;
    }
    // Include this element
    temp.push_back(nums[index]);
    subsequence(nums,index+1, n, temp, ans);
    temp.pop_back();


    while(index+1<n && nums[index] == nums[index+1] ){
        index++;
    }
    //Not include this element 
    subsequence(nums,index+1, n, temp, ans);

   
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int startig_index = 0;
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;

        subsequence(nums, startig_index, n, temp , ans);

        return ans;
        
    }
};